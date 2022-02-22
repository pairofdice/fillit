/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:54:45 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/22 18:45:54 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	parse_piece(char *input)
{
	int	i;
	char *first_part;
	char *next_part;
	int x;
	int y;
	printf("hello\n");

	first_part = ft_strchr(input, '#');
	next_part = first_part;
	i = 0;
	x = (first_part - input) % 5;
	y = (first_part - input) / 5;
	printf("    % d % d\n", x, y);
	while (i < 3)
	{
		next_part = ft_strchr(++next_part, '#');
 		printf("% d  ", (next_part - first_part));
		printf("% d,", ((next_part - input) % 5) - x );
		printf("% d\n", ((next_part - input) / 5) - y);
		i++;
	}
}
