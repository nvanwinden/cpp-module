# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/17 16:33:37 by nvan-win      #+#    #+#                  #
#    Updated: 2022/04/06 09:47:16 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = 		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98
NAME = 		replacer
INC_DIR =	./includes/
SRC_DIR = 	./src/
OBJ_DIR = 	./obj/
TST_DIR =	./tests/
HEADER =	$(INC_DIR)Replace.hpp
OBJ_FILES =	$(OBJ_DIR)main.o \
			$(OBJ_DIR)Replace.o

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@echo "clean..."
	rm -rf $(OBJ_DIR)
	rm -rf $(TST_DIR)*.replace

fclean: clean
	@echo "fclean..."
	rm -f $(NAME)

re: fclean all

test:
	./replacer $(TST_DIR)empty word "another word"
	./replacer $(TST_DIR)multiple multiple several
	./replacer $(TST_DIR)single oops hooray
	./replacer $(TST_DIR)identical whatever whatever

.PHONY: all clean fclean re test
