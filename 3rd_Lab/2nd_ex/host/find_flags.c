// C library headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()


#define MORE_THAN_64 70
#define ACTUAL_BUFF_SIZE 64

char input[MORE_THAN_64] = "";
char output[2] = "";

int main(int argc, char *argv[]){

    // Create new termios struct
    struct termios tty;

    // Open input tty
    int tty_fd;

    tty_fd = open(argv[1], O_RDWR | O_NOCTTY);

    if(tty_fd == -1){

        fprintf(stderr, "Cannot open input tty.\n");
        exit(4);

    }

    // Read in existing settings, and handle any error
    if(tcgetattr(tty_fd, &tty) != 0) {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
        return 1;
    }

    // Control Modes (c_cflag)
    tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity
    tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication
    tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size
    tty.c_cflag |= CS8; // 8 bits per byte
    tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

    printf("tty.c_cflag = %d\n", tty.c_cflag);

    // Local Modes (c_lflag)
    tty.c_lflag |= ICANON; //Disable Canonical mode
    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP

    printf("tty.c_lflag = %d\n", tty.c_lflag);

    // Input Modes (c_iflag)
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

    printf("tty.c_iflag = %d\n", tty.c_iflag);

    // Output Modes (c_oflag)
    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

    printf("tty.c_oflag = %d\n", tty.c_oflag);
    
    tty.c_cc[VTIME] = 0;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 1;

    // printf("tty.c_cc = %d\n", tty.c_cc);printf("tty.c_lflag = %d\n", tty.c_lflag);
    printf("tty_input_output speed = %d\n", 0000015);

    int i;
    for(i = 0; i < 17; i++){
        printf("tty_c_cc[%d] = %d\n", i, tty.c_cc[i]);
    }

    close(tty_fd);
}
