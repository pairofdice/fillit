/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:19:54 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/22 13:49:55 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <time.h>
#include <fcntl.h>
#include <stdio.h>
//#include <sys/types.h>
//#include <sys/uio.h>
//#include <unistd.h>
//#include <stdlib.h>

/* Testing main */

int test_parse()
{
	int fd;
	int ret;
	char test_input[22];

	fd = open("one_piece1", O_RDONLY);
	ret = read(fd, test_input, 22);
	test_input[21] = '\0';
	
	parse_piece(test_input);

		fd = open("one_piece2", O_RDONLY);
	ret = read(fd, test_input, 22);
	test_input[21] = '\0';
	
	parse_piece(test_input);
	
}

int main(int argc, char **argv)
{
	test_parse();
		
}