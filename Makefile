# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 12:59:18 by ncsomori          #+#    #+#              #
#    Updated: 2022/02/23 12:03:07 by jsaarine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

S = src/

SRC = $Smain.c \
	  $Svalidate.c \
	  $Sparse.c

HDR = $Sfillit.h

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wconversion

RM = /bin/rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -I $(HDR) -L. libft/libft.a

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
