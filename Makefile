CC = gcc 
CFLAGS = -Wall -Wextra -Werror
DEBUGG = -fsanitize=address -g

SRC = main.c \
	  helper.c 

TARGET = executable


all: $(TARGET)

$(TARGET): 
	$(CC) $(CFLAGS)  -o $(TARGET) $(SRC)


clean:
	rm -f $(OBJ) $(TARGET)

fclean: clean
	rm -f $(TARGET)
run:
	./$(TARGET)

dev:
	$(CC) $(CFLAGS) $(DEBUGG) -o $(TARGET) $(SRC)

re: fclean all

redev: fclean dev
