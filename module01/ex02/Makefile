# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/17 15:25:58 by nvan-win      #+#    #+#                  #
#    Updated: 2022/04/06 09:10:53 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = 		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98
NAME = 		brain
INC_DIR =	./includes/
SRC_DIR = 	./src/
OBJ_DIR = 	./obj/
OBJ_FILES =	$(OBJ_DIR)main.o

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
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
