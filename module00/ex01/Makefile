CC = 		c++
CFLAGS = 	-Wall -Wextra -Werror
NAME = 		phonebook
INC_DIR =	./includes/
SRC_DIR = 	./src/
OBJ_DIR = 	./obj/
HEADER =	$(INC_DIR)Contact.hpp \
			$(INC_DIR)Phonebook.hpp
OBJ_FILES =	$(OBJ_DIR)main.o \
			$(OBJ_DIR)Contact.o \
			$(OBJ_DIR)Phonebook.o

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<
	
clean:
	@echo "Cleaning..."
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Extra cleaning..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
