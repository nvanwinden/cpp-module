CC = 		c++
CFLAGS = 	-Wall -Wextra -Werror
NAME = 		account
INC_DIR =	./includes/
SRC_DIR = 	./src/
OBJ_DIR = 	./obj/
HEADER =	Account.hpp
OBJ_FILES =	$(OBJ_DIR)Account.o \
			$(OBJ_DIR)tests.o

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC_DIR)$(HEADER)
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
