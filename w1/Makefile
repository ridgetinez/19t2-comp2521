CC=gcc
CFLAGS=-Wall -Werror

all: sumList

sumList: sumList.o linkedlist.o
	$(CC) $(CFLAGS) -o sumList linkedlist.o sumlist.o

sumList.o: sumList.c linkedlist.h
	$(CC) $(CFLAGS) -c sumList.c linkedlist.h

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c 

clean:
	rm *.o sumList