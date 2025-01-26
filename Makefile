CC = gcc
CFLAGS = -Wall -Wextra -pedantic
SRC = src/main.c src/carta.c src/baralho.c src/jogo.c
INC = -Iinclude
OBJ = $(SRC:.c=.o)
TARGET = super_trunfo_futebol

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
    $(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
    rm -f $(OBJ) $(TARGET)
