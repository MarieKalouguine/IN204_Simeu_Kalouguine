FLAGS = -Wall -std=c++11

SRCFILES = objects.cpp test.cpp intersect.cpp
OBJFILES=$(SRCFILES:%.cpp=$(OBJPATH)%.o)
OBJPATH=./obj/
SRCPATH=./src/

all: main

main : $(OBJFILES)
	g++ $(FLAGS) -o $@ $^

$(OBJPATH)%.o : $(SRCPATH)%.cpp $(SRCPATH)objects.hpp
	@mkdir -p $(OBJPATH)
	(cd $(OBJPATH); g++ $(FLAGS) -c ../$<)


clean :
	rm -rf $(OBJPATH) core main *.gch
