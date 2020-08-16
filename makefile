CC = gcc
CFLAGS = -Wall

all: bitManipulations.o main.c helperFunctions.o
		$(CC) $(CFLAGS) bitManipulations.o helperFunctions.o main.c -o main

bitManipulations.o: bitManipulations.c
						$(CC) $(CFLAGS) -c bitManipulations.c

helperFunctions.o: helperFunctions.c
						$(CC) $(CFLAGS) -c helperFunctions.c

clean: 
		rm *.o