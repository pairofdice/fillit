/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:19:54 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/21 12:19:58 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <time.h>
#include <stdio.h>
#include <fcntl.h>
//#include <sys/types.h>
//#include <sys/uio.h>
//#include <unistd.h>
//#include <stdlib.h>

/* Testing main */
int test_main(int argc, char **argv)
{
	int i;
	int fd;
	char	*tests[] = {
		"one_piece",
		0};


	i = 0;
	while (tests[i])
	{
		main(2, tests[i]);

	}
}