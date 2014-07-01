CC_FLAGS=-std=c99 -Wall -Wpedantic -pipe

all: libstuff.so check_libstuff.out
	 LD_LIBRARY_PATH=$(shell pwd):${LD_LIBRARY_PATH} ./check_libstuff.out

libstuff.so: libstuff.o
	gcc -shared -pipe -o libstuff.so libstuff.o

libstuff.o: libstuff.c
	gcc -c ${CC_FLAGS} -fpic -o libstuff.o libstuff.c

check_libstuff.out: check_libstuff.c
	gcc -L$(shell pwd) ${CC_FLAGS} -o check_libstuff.out -lcheck  -lstuff check_libstuff.c
