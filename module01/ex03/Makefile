# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/17 16:04:18 by nvan-win      #+#    #+#                  #
#    Updated: 2022/04/06 09:19:12 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = 		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98
NAME = 		weapon
INC_DIR =	./includes/
SRC_DIR = 	./src/
OBJ_DIR = 	./obj/
HEADER =	$(INC_DIR)Weapon.hpp \
			$(INC_DIR)HumanA.hpp \
			$(INC_DIR)HumanB.hpp
OBJ_FILES =	$(OBJ_DIR)main.o \
			$(OBJ_DIR)Weapon.o \
			$(OBJ_DIR)HumanA.o \
			$(OBJ_DIR)HumanB.o

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
