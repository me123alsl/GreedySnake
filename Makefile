.PHONY: clean all

TARGET = greedysnake
CC = gcc
SRC = greedysnake.c welcome.c die.c
OBJ = greedysnake.o welcome.o die.o
LDFLAGS = -lncurses

# Uncomment and edit the line below if necessary
# CFLAGS = -I/usr/include/ncurses

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(SRC) $(LDFLAGS)

clean:
	rm -rf $(TARGET) $(OBJ) 
