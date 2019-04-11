
CFLAGS=-I. -g 
LDFLAGS= -g
SOURCE_FILES= simulate.c sim.h sim.c inst.h 
CONTROL_FILES = Makefile 
TESTS = tests
CC=cc

all: sim 

sim: sim.o simulate.o
	$(CC) -o sim $(LDFLAGS) sim.o simulate.o

debug: simdbg

tar:
	tar cfv sim.tar $(SOURCE_FILES) $(CONTROL_FILES) $(TESTS)

simdbg:
	cc -o simdbg -DDEBUG sim.c simulate.c

clean:
	rm -f *.o sim simdbg

clobber: clean

install: 
	make clobber
	make all

sim.o: sim.c sim.h
simulate.o: simulate.c sim.h inst.h
