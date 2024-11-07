CC = gcc
CFLAGS = -Wall -std=c99 -g

all: func_ptr

func_ptr: func-ptr.o util.o
    $(CC) $(CFLAGS) -o func_ptr func-ptr.o util.o

func-ptr.o: func-ptr.c process.h util.h
    $(CC) $(CFLAGS) -c func-ptr.c

util.o: util.c process.h util.h
    $(CC) $(CFLAGS) -c util.c

clean:
    rm -f *.o func_ptr
