CC = 		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98
NAME = 		forms
INC_DIR =	./includes/
SRC_DIR = 	./src/
OBJ_DIR = 	./obj/
HEADER =	$(INC_DIR)Bureaucrat.hpp \
			$(INC_DIR)AForm.hpp \
			$(INC_DIR)ShrubberyCreationForm.hpp \
			$(INC_DIR)RobotomyRequestForm.hpp \
			$(INC_DIR)PresidentialPardonForm.hpp
OBJ_FILES =	$(OBJ_DIR)main.o \
			$(OBJ_DIR)Bureaucrat.o \
			$(OBJ_DIR)AForm.o \
			$(OBJ_DIR)ShrubberyCreationForm.o \
			$(OBJ_DIR)RobotomyRequestForm.o \
			$(OBJ_DIR)PresidentialPardonForm.o

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
