/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:19:54 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/23 12:02:26 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include "../src/fillit.h"
//#include <sys/types.h>
//#include <sys/uio.h>
//#include <unistd.h>
//#include <stdlib.h>

/* Testing main */

int test_parse()
{
	int i;
	int k;
	char test_input[22];
	t_piece piece;
	char	*tests[] = {
		"one_piece1",
		"one_piece2",
		"one_piece3",
		"one_piece4",
		"one_piece5",
		0};

	printf("\n");
	i = 0;
	while (tests[i])
	{
		if (i > 0)
			printf("-------\n");
		read(open(tests[i], O_RDONLY), test_input, 22);
		test_input[21] = '\0';
		printf("%s\n",test_input);
		parse_piece(test_input, &piece);
		k = 0;
		while (k < 3)
		{
			printf("% d, % d\n", piece.offsets[k*2], piece.offsets[k*2 + 1]);
			k++;
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	test_parse();
	return (0);
}
