CC = g++
FLAGS = -Wall -std=c++11

all: main

main : objects.o test.o intersect.o
	$(CC) $(FLAGS) -o $@ $^
	
%.o : %.cpp
	$(CC) $(FLAGS) -c $^

test.cpp : objects.hpp intersect.hpp
objects.cpp : objects.hpp
intersect.cpp : intersect.hpp objects.hpp


clean :
	rm -rf *.o core main *.gch
