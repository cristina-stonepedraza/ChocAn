CFLAGS=-g -Wall
CC=g++
BIN=executable
all:
	$(CC) $(CFLAGS) main.cpp implementations/* -o $(BIN)
clean:
	$(RM) $(BIN)