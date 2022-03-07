# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 12:59:18 by ncsomori          #+#    #+#              #
#    Updated: 2022/03/06 12:09:22 by jsaarine         ###   ########.fr        #
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
LIBA = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = /bin/rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIBA)

$(LIBA):
	make -C $(LIBFT)

%.o: %.c $(LIBA) $(HDR)
	gcc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
