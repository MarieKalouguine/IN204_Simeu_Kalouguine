FLAGS = -Wall -std=c++11

SRCPATH=./src/
OBJPATH=./obj/
OBJFILES = $(addprefix $(OBJPATH), objects.o test.o intersect.o lighting.o)
HEADERS = $(addprefix $(SRCPATH), objects.hpp environment.hpp)

all: main

main : $(OBJFILES)
	g++ $(FLAGS) -o $@ $^

$(OBJPATH)%.o : $(SRCPATH)%.cpp $(HEADERS)
	@mkdir -p $(OBJPATH)
	(cd $(OBJPATH); g++ $(FLAGS) -c ../$<)


clean :
	rm -rf $(OBJPATH) core main *.gch
