CC=g++
CFLAGS=-g -Wall -Wshadow -Wvla -Werror -pedantic
DEBUG=gdb
SRC_H=stack.h matrix.h
SRC_C=stack.cpp matrix.cpp proc.cpp main.cpp
EXECUTABLE=word-search

$(EXECUTABLE):$(SRC_H) $(SRC_C)
	$(CC) -o word-search $(CFLAGS) stack.cpp matrix.cpp proc.cpp main.cpp

debug:
	$(DEBUG) word-search

clean:
	rm ./$(EXECUTABLE)
