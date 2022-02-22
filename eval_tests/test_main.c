/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:19:54 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/22 18:50:28 by jsaarine         ###   ########.fr       */
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
	int i;
	int fd;
	int ret;
	char test_input[22];
	char	*tests[] = {
		"one_piece1",
		"one_piece2",
		"one_piece3",
		"one_piece4",
		"one_piece5",
		0};

	while (tests[i])
	{
		fd = open(tests[i], O_RDONLY);
		ret = read(fd, test_input, 22);
		test_input[21] = '\0';
		parse_piece(test_input);
		i++;
	}
}

int main(int argc, char **argv)
{
	test_parse();
}
