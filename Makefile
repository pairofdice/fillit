# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 12:59:18 by ncsomori          #+#    #+#              #
#    Updated: 2022/02/22 13:09:29 by ncsomori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

S = src/

SRC = $Smain.c \
	  $Svalidate.c

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
