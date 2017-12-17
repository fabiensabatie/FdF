# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 21:06:58 by fsabatie          #+#    #+#              #
#    Updated: 2017/12/17 14:03:03 by fsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re
# Defining variables

NAME = fdf

SRC_PATH = srcs
INC_PATH = includes
LIB_PATH = $(INC_PATH)/libft
SRC_NAME =	fdf.c \
			drawers.c \
			dots.c \
			reader.c \
			events.c

LIB_NAME = libft.a
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))
CPPFLAGS = -Wall -Werror -Wextra
FLAGS =  -lmlx -framework OpenGL -framework AppKit
# Defining colors

RED = \033[1;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[1;36m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
WHITE = \033[0;97m

# Defining rules

all: $(NAME)

$(NAME):
	@echo "${GREEN}Compiling libft." | tr -d '\n'
	@make re -C $(LIB_PATH) && make clean -C $(LIB_PATH)
	@echo " ${GREEN}[OK]"
	@echo "${GREEN}Compiling fdf." | tr -d '\n'
	@gcc $(CPPFLAGS) -c $(SRC)
	@gcc $(CPPFLAGS) $(OBJ_NAME) -o $(NAME) $(LIB) $(FLAGS)
	@echo " ${GREEN}[OK]"
	@echo "${WHITE}Oh my god, a wild ${RED}U${ORANGE}N${YELLOW}\
	I${GREEN}C${BLUE}O${PURPLE}R${RED}N \
	${WHITE}just pooped a FdF file !"
clean:
	@rm -rf $(OBJ_NAME)
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_PATH)

re: fclean all
