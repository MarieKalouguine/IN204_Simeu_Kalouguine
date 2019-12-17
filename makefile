CC = g++

all: test.out

test.out : objects.h test_objects.cpp
	$(CC) -o $@ $^

clean :
	rm -rf *.o *.out core
