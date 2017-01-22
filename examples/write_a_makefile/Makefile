# define constants
cc=gcc
cflags=-Wall

# 1. myobjs  equals to t.o and h.o
# 2. "\" allows multilines
myobjs = t.o \
	h.o
# my_exe is a exe file
# $./my_exe   // it execute my_exe
my_exe : $(myobjs)
	cc -o my_exe $(myobjs)
# t.o is a target file
# t.o depends t.c hello.h
# if t.c or hello.h updated, then compile like "cc -c t.c"
t.o : t.c hello.h
	cc -c t.c
# h.o is a target file
# h.o depends h.c hello.h
# if h.c or hello.h updated, then compile h.c like "cc -c h.c"
h.o : h.c hello.h
	cc -c h.c
# $make clean // it will clean object files and exe
clean:
	rm my_exe $(myobjs)
