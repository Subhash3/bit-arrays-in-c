CC = gcc
CFLAGS = -Wall

all: bitManipulations.o main.c
		$(CC) $(CFLAGS) bitManipulations.o main.c -o main

bitManipulations.o: bitManipulations.c
						$(CC) $(CFLAGS) -c bitManipulations.c

clean: 
		rm *.o