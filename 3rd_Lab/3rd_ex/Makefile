CC = gcc
CFLAGS = -Wall -g 

all: main 

string_manipulation.o: string_manipulation.c
	$(CC) $(CFLAGS) string_manipulation.c -c 
strcmp.o: strcmp.s
	$(CC) $(CFLAGS) strcmp.s -c
strcpy.o: strcpy.s
	$(CC) $(CFLAGS) strcpy.s -c
strcat.o: strcat.s
	$(CC) $(CFLAGS) strcat.s -c
strlen.o: strlen.s
	$(CC) $(CFLAGS) strlen.s -c

main: strcmp.o strcpy.o strcat.o strlen.o string_manipulation.o
	$(CC) strcmp.o strcpy.o strcat.o strlen.o string_manipulation.o -o main


clean:
	rm -f *.o *.out
	rm main