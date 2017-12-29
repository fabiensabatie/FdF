# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:18:12 by fsabatie          #+#    #+#              #
#    Updated: 2017/12/17 14:08:20 by fsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME =  ft_strjoin_char.c \
			ft_strjoinfree.c \
			ft_putendl_fd.c \
			ft_putchar_fd.c \
			get_next_line.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_lstdelone.c \
			ft_memalloc.c \
			ft_striteri.c \
			ft_strsplit.c \
			ft_putnexit.c \
			ft_strnequ.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_putchar.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_strncpy.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_striter.c \
			ft_strmapi.c \
			ft_putendl.c \
			ft_lstiter.c \
			ft_strcsub.c \
			ft_lstmap.c \
			ft_strsub.c \
			ft_lstnew.c \
			ft_strnew.c \
			ft_strequ.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_memdel.c \
			ft_strmap.c \
			ft_strdel.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_memcmp.c \
			ft_memchr.c \
			ft_strstr.c \
			ft_strcmp.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strstr.c \
			ft_strcat.c \
			ft_strlen.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_strrev.c \
			ft_bzero.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_abs.c

OBJ_NAME = $(SRC_NAME:.c=.o)

CPPFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	@gcc $(CPPFLAGS) -c $(SRC_NAME)
	@ar rc $(NAME) $(OBJ_NAME)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_NAME)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
