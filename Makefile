#define macros
CC = gcc
CFLAGS = -Wall -std=c99
TARGET = ponggcc --version
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
all: $(TARGET)

# convert all the c files to o files
$(TARGET): $(OBJ)
	$(CC) -o $@ $^ -lm

# compile
%.o: %.c lab2_header.h stats_tools.h
	$(CC) $(CFLAGS) -c $< -o $@

# when make clean to get rid of o files
clean:
	rm -f $(OBJ) $(TARGET)
    
.PHONY: all clean