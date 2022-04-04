FLAGS = -g -Wall
CC = gcc
.PHONY: clean

all: signal

signal: signal.o
	$(CC) $(FLAGS) -o signal signal.o

signal.o: signal.c
	$(CC) $(FLAGS) -c signal.c


clean:
	rm -f *.o *.a *.so signal



