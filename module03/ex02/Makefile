CC = 		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98
NAME = 		fragtrap
INC_DIR =	./includes/
SRC_DIR = 	./src/
OBJ_DIR = 	./obj/
HEADER =	$(INC_DIR)ClapTrap.hpp \
			$(INC_DIR)ScavTrap.hpp \
			$(INC_DIR)FragTrap.hpp
OBJ_FILES =	$(OBJ_DIR)main.o \
			$(OBJ_DIR)ClapTrap.o \
			$(OBJ_DIR)ScavTrap.o \
			$(OBJ_DIR)FragTrap.o

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@echo "clean..."
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "fclean..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
