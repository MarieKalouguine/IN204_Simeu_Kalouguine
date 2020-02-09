FLAGS = -Wall -std=c++11

SRCPATH=./src/
OBJPATH=./obj/
TESTPATH=./tests/
OBJFILES = $(addprefix $(OBJPATH), test.o math_objects.o shape.o light_source.o camera.o environment.o initialization.o)
HEADERS = $(addprefix $(SRCPATH), math_objects.hpp shape.hpp light_source.hpp environment.hpp camera.hpp)

default: main

main : $(OBJFILES)
	g++ $(FLAGS) -o $@ $^

test_xml : $(OBJPATH)tinyxml2.o $(OBJPATH)test_xml.o
	g++ $(FLAGS) -o $@ $^

$(OBJPATH)test%.o : $(TESTPATH)test%.cpp $(HEADERS)
	@mkdir -p $(OBJPATH)
	(cd $(OBJPATH); g++ $(FLAGS) -c ../$<)

$(OBJPATH)%.o : $(SRCPATH)%.cpp $(HEADERS)
	@mkdir -p $(OBJPATH)
	(cd $(OBJPATH); g++ $(FLAGS) -c ../$<)


clean :
	rm -rf $(OBJPATH) core main test_xml
