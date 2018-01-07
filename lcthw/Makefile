cc=gcc
cflags=-Wall -g -std=c11
basic.obj = basic.o index.o
#target "co" should be on the top postion
#("co" .exe depends on "basic.o", "index.o")
co:	$(basic.obj)
#(cc -o "basic.o", "index.o" to generate "co" .exe)
	cc $(cflags) -o co $(basic.obj)

#(basic.o depends on "basic.c", "basic.h")
basic.o: ./basic/basic.c ./basic/basic.h
#(cc -c "basic.c" to generate basic.o)
	cc $(cflags) -c ./basic/basic.c 

#(basic.o depends on "index.c", "basic.h")
index.o: index.c ./basic/basic.h
#(cc -c "index.c" to generate index.o)
	cc $(cflags) -c index.c

#make => automatically generate co

#make run => ./co
run:
	./co

#make clean => rm -rf *.o co
.PHONY: clean
clean:
		-rm -rf $(basic.obj) co co.dSYM