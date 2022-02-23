# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 12:59:18 by ncsomori          #+#    #+#              #
#    Updated: 2022/02/22 23:29:08 by jsaarine         ###   ########.fr        #
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

test:
	rm test_exe
	gcc -o test_exe eval_tests/test_main.c src/parse.c libft/*.c
	./test_exe
