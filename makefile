CC = g++
FLAGS = -Wall -std=c++11

all: main

main : objects.o test.o
	$(CC) $(FLAGS) -o $@ $^

objects.o : objects.cpp objects.hpp
	$(CC) $(FLAGS) -c $<


test.o : test.cpp objects.hpp
	$(CC) $(FLAGS) -c $<

clean :
	rm -rf *.o core main *.gch
