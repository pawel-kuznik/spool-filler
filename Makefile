# compiler and compiler flags
CC = g++
CC_FLAGS = -Wall -O2 -std=c++1y
LIBS = -pthread

#
#	Location of the executable
#
EXEC = build/spool-filler

#
#	All the source files from this project
#
SOURCES = $(wildcard src/*.cpp)

#
#	Path to object files
#
OBJECTS = $(SOURCES:.cpp=.o)

#
#	The name of the tasks
#
.PHONY: all run clean init

# 
#	The main target
#
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(LIBS)

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@ $(LIBS)

# To obtain everything
all: $(EXEC)

#
#	Rule to run compiled binary
#
run:
	$(EXEC) sample/test.txt sample/test_copy.txt 1000

#
#	Rule to clean the workspace.
#
clean:
	rm -f $(EXEC) $(OBJECTS)
	# cd tests && make clean && cd ..

#
#	Rule to prepare the workspace with tmp directories and similar stuff
#
init:
	mkdir -p build
