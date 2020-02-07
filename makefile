FLAGS = -Wall -std=c++11

SRCPATH=./src/
OBJPATH=./obj/
OBJFILES = $(addprefix $(OBJPATH), test.o math_objects.o shape.o light_source.o environment.o initialization.o)
HEADERS = $(addprefix $(SRCPATH), math_objects.hpp shape.hpp light_source.hpp environment.hpp)

all: main

main : $(OBJFILES)
	g++ $(FLAGS) -o $@ $^

$(OBJPATH)%.o : $(SRCPATH)%.cpp $(HEADERS)
	@mkdir -p $(OBJPATH)
	(cd $(OBJPATH); g++ $(FLAGS) -c ../$<)


clean :
	rm -rf $(OBJPATH) core main
