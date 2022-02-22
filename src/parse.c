/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:54:45 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/22 13:51:03 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	parse_piece(char *input)
{
	int	i;
	char *first_part;
	char *next_part;
	printf("hello\n");
	
	first_part = ft_strchr(input, '#');
	next_part = first_part;
	i = 0;
	while (i < 3)
	{
		next_part = ft_strchr(++next_part, '#');
 		printf("% d  ", (next_part - first_part));
		printf("% d,", (next_part - first_part) % 5 - (next_part - first_part) / 5 + 1); 
		printf("% d\n", (next_part - first_part) / 5);
		i++;
	}
}