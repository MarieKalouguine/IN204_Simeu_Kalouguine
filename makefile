CC = g++

all: test.exe

test.exe : objects.h test_objects.cpp
	$(CC) -o $@ $^

clean :
	rm -rf *.o *.exe core
