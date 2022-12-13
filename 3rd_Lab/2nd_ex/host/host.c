// C library headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

// Linux headers
#include <fcntl.h>   // Contains file controls like O_RDWR
#include <errno.h>   // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h>  // write(), read(), close()

#define ACTUAL_BUFF_SIZE 67
#define PLUS_SLASH_N_AND_ONE_MORE 66

int main(int argc, char **argv)
{

    char input[ACTUAL_BUFF_SIZE] = "";
    char output[10] = "";

    // tty file descriptor
    int tty_fd;

    // Create new termios struct
    struct termios tty;

    // Check for input arguments
    if (argc != 2)
    {

        fprintf(stderr, "Invalid number of arguments, please provide only the serial port path!\n");
        exit(2);
    }

    printf("Please give a string to send to host:\n");

    // ssize_t rcnt = read(0, input, PLUS_SLASH_N_AND_ONE_MORE);

    // if (rcnt < 0)
    // {
    //     perror("read");
    //     exit(1);
    // }

    // if (rcnt == 66)
    // {
    //     fprintf(stderr, "Host: string is more than 64 bytes!\n");
    //     fflush(0);
    //     exit(1);
    // }

    // We prefere the previous way of reading in order to get \n without filling the input array with spaces as it is shown below

    // fflush(0);

    fscanf(stdin, " %[^\n]s", input);

    // printf("input = %s\n", input);

    if (input[64] != '\0'){

        fprintf(stderr, "Maximum number of characters is 64.\n");
        exit(3);

    }

    int i;
    for(i = 0; i < ACTUAL_BUFF_SIZE; i++){
        if(input[i] == '\0') {
            input[i] = '\n';
            // printf("%d\n", i);
            break;
        }
    }

    // printf("input = %s\n", input);

    // Open input tty

    tty_fd = open(argv[1], O_RDWR | O_NOCTTY);

    // fflush(tty_fd);

    if (tty_fd == -1)
    {

        fprintf(stderr, "Cannot open input tty.\n");
        exit(4);
    }

    // Read in existing settings, and handle any error
    if (tcgetattr(tty_fd, &tty) != 0)
    {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
        return 1;
    }

    // Control Modes (c_cflag)
    tty.c_cflag &= ~PARENB;        // Clear parity bit, disabling parity
    tty.c_cflag &= ~CSTOPB;        // Clear stop field, only one stop bit used in communication
    tty.c_cflag &= ~CSIZE;         // Clear all bits that set the data size
    tty.c_cflag |= CS8;            // 8 bits per byte
    tty.c_cflag &= ~CRTSCTS;       // Disable RTS/CTS hardware flow control
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

    // Local Modes (c_lflag)
    tty.c_lflag |= ICANON; // Enable Canonical mode (from guest we will \n in order to stop)
    tty.c_lflag &= ~ECHO;   // Disable echo
    tty.c_lflag &= ~ECHOE;  // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG;   // Disable interpretation of INTR, QUIT and SUSP

    // Input Modes (c_iflag)
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);                                      // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL); // Disable any special handling of received bytes

    // Output Modes (c_oflag)
    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

    tty.c_cc[VTIME] = 0; // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 1;

    // Some configuration could have been done with cfmakeraw() function, but we did each confing this way in order to explain the why

    // Set in/out baud rate to be 9600
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    // Save tty settings, also checking for error
    if (tcsetattr(tty_fd, TCSANOW, &tty) != 0)
    {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
        return 1;
    }

    tcflush(tty_fd, TCIOFLUSH); /* Flush tty buffer */

    // Read user input
    // fscanf(stdin, "%s", input);

    write(tty_fd, input, ACTUAL_BUFF_SIZE);

    // fscanf(tty_fd, "%c %d", output[0], output[1]);

    read(tty_fd, output, 10);

    printf("%d\n", output[0]);

    char most_frequent_character = output[2];
    char times = output[0] - '0';

    if (times != 0)
        printf("The most frequent character is\n %c \nand it appeared %d times.\n", most_frequent_character, times);

    else
        printf("No characters were given\n");

    close(tty_fd);
    return 0;
}