#SOURCES specifies which files to compile as part of the project
SOURCES = src/*.c

#COMPILER specifies which compiler we're using
COMPILER = gcc

#INCLUDE_DIRS specifies the additional include paths we'll need
INCLUDE_DIRS = -ISDL2\include\SDL2

#LIBRARY_DIRS specifies the additional library paths we'll need
LIBRARY_DIRS = -LSDL2\lib

#FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
FLAGS = -Wall -Werror -Wextra -pedantic

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2
LINUX_LINKER_FLAGS = -lSDL2 -lm

#EXECUTABLE specifies the name of our exectuable
EXECUTABLE = maze

#This is the target that compiles our executable
all : $(SOURCES)
	$(COMPILER) $(SOURCES) $(INCLUDE_DIRS) $(LIBRARY_DIRS) $(FLAGS) $(LINKER_FLAGS) -o $(EXECUTABLE)

#Linux SDL compiling
linux : $(SOURCES)
	$(COMPILER) $(SOURCES) $(FLAGS) $(LINUX_LINKER_FLAGS) -DLINUX -o $(EXECUTABLE)

#Linux SDL installation
linux_install : 
	sudo apt-get install libsdl2-dev

#MAC SDL compiling
mac : $(SOURCES)
	$(COMPILER) $(SOURCES) $(FLAGS) $(LINUX_LINKER_FLAGS) -DMAC -o $(EXECUTABLE)