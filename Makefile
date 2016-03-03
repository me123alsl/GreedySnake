.PHONY: clean all

TARGET = greedysnake
CC = gcc
SRC = greedysnake.c welcome.c levelchoice.c die.c snake.c
OBJ = greedysnake.o welcome.o levelchoice.o die.o snake.o
LDFLAGS = -lncurses

# Uncomment and edit the line below if necessary
# CFLAGS = -I/usr/include/ncurses

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(SRC) $(LDFLAGS)

clean:
	rm -rf $(TARGET) $(OBJ) 
