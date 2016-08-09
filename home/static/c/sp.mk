CC = gcc
CPP = g++
OBJS = $(patsubst %.c, %.o, $(wildcard ./*.c))
OBJS_CPP = $(patsubst %.cpp, %.o, $(wildcard ./*.cpp))
#OBJS = BAD_INCLUDE.INVALID_PATH.o 
#OBJS = UNBOUNDED_SOURCE_TO_ARRAY.o
all: clean $(OBJS) $(OBJS_CPP)

.c.o:
	@$(CC) -c $*.c
.cpp.o:
	@$(CPP) -c $*.cpp
clean:
	@rm -rf *.o

