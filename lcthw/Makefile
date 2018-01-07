cc=gcc
cflags=-Wall -std=c11

basic: cc -c ./basic/*.c basic.h

co:
	cc -Wall -g -c ./index.c -o $(basic) co

run:
	./co

clean:
		rm -rf *.o co