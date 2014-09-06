#OPTIONS=-std=c++11 -g -O2 -lstdc++ -lm


# compile all .cpp files

#SRCS=$(wildcard *.cpp)

#OBJS=$(SRCS:.cpp=)

#all: $(OBJS)

#%: %.cpp
	#g++ $(OPTIONS) $< -o $@

all: example sdlexample

example: example.cpp
	g++ -lm $< -o $@

sdlexample: sdlexample.cpp
	g++ $< `pkg-config --cflags --libs sdl` -o $@
	
clean: 
	#rm -f $(OBJS)
	rm -f example
	rm -f sdlexample
	rm -f tags

# phony targets do not refer to a file but a command
# http://www.gnu.org/software/make/manual/html_node/Phony-Targets.html
.PHONY: all clean
