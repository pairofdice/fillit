# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 12:59:18 by ncsomori          #+#    #+#              #
#    Updated: 2022/03/05 19:10:28 by ncsomori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

S = src/

SRC = $Smain.c \
	  $Svalidate.c \
	  $Sparse.c \
	  $Ssolve.c 

HDR = $Sfillit.h

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = /bin/rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -I /src -L. libft/libft.a

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
