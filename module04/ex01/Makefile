CC = 		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98
NAME = 		brain
INC_DIR =	./includes/
SRC_DIR = 	./src/
OBJ_DIR = 	./obj/
HEADER =	$(INC_DIR)Animal.hpp \
			$(INC_DIR)Cat.hpp \
			$(INC_DIR)Dog.hpp \
			$(INC_DIR)WrongAnimal.hpp \
			$(INC_DIR)WrongCat.hpp \
			$(INC_DIR)Brain.hpp
OBJ_FILES =	$(OBJ_DIR)main.o \
			$(OBJ_DIR)Animal.o \
			$(OBJ_DIR)Cat.o \
			$(OBJ_DIR)Dog.o \
			$(OBJ_DIR)WrongAnimal.o \
			$(OBJ_DIR)WrongCat.o \
			$(OBJ_DIR)Brain.o

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
