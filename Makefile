.PHONY: clean all

TARGET = greedysnake
CC = gcc
SRC = greedysnake.c welcome.c
OBJ = greedysnake.o welcome.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(SRC) -lcurses

clean:
	rm -rf $(TARGET) $(OBJ) 
