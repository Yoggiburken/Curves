NAME = Curves
CC=g++
CPPLIBS=  -framework sfml-graphics -framework sfml-audio -framework sfml-network -framework sfml-window -framework sfml-system
#CPPFLAGS=

## Dependencies ##
CPP_FILES=$(wildcard src/*.cpp)
HPP_FILES=$(wildcard include/*.hpp)
OBJ_FILES=$(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

## Targets ##

all: $(NAME)

$(NAME): $(OBJ_FILES)
	g++ -o $@ $^ $(CPPLIBS)

obj/%.o: src/%.cpp
	g++ -c -o $@ $<

src/%.cpp: include/%.hpp
	g++ -c -o obj/%.o $@

clean: 
	rm $(OBJ_FILES) $(NAME)
