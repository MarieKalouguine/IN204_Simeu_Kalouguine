FLAGS = -Wall -std=c++11

SRCPATH=./src/
OBJPATH=./obj/
OBJFILES = $(OBJPATH)objects.o $(OBJPATH)test.o $(OBJPATH)intersect.o

all: main

main : $(OBJFILES)
	g++ $(FLAGS) -o $@ $^

$(OBJPATH)%.o : $(SRCPATH)%.cpp $(SRCPATH)objects.hpp
	@mkdir -p $(OBJPATH)
	(cd $(OBJPATH); g++ $(FLAGS) -c ../$<)


clean :
	rm -rf $(OBJPATH) core main *.gch
