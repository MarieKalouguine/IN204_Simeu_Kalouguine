FLAGS = -Wall -std=c++11

SRCFILES = objects.cpp test.cpp intersect.cpp
OBJFILES=$(SRCFILES:%.cpp=%.o)

all: main

main : $(OBJFILES)
	g++ $(FLAGS) -o $@ $^

.cpp.o : objects.hpp
	g++ $(FLAGS) -c $<


clean :
	rm -rf *.o core main *.gch
