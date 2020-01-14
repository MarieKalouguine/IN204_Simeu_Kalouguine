CC = g++
FLAGS = -Wall -std=c++11

OBJ = objects.o test.o intersect.o

all: main

main : $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

%.o : %.cpp objects.hpp
	$(CC) $(FLAGS) -c $^

test.cpp : objects.hpp
objects.cpp : objects.hpp
intersect.cpp : objects.hpp


clean :
	rm -rf *.o core main *.gch
