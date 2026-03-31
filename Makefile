CC = gcc
CFLAGS = -Wall -std=c99 -IC:/msys64/ucrt64/include
TARGET = p.exe
SRC = $(wildcard *.c) # grab everything thats a c file int the folder
OBJ = $(SRC:.c=.o) # imagine a version where all the c files are o files
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ -LC:/msys64/ucrt64/lib -lmingw32 -lSDL2main -lSDL2 -lm

# compile
%.o: %.c pong.h 
	$(CC) $(CFLAGS) -c $< -o $@

# when make clean to get rid of o files
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean