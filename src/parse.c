/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:54:45 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/22 22:46:44 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"
#include "fillit.h"

void	parse_piece(char *input, t_piece *piece)
{
	int	i;
	int i2;
	char *first;
	char *next;

	first = ft_strchr(input, '#');
	next = first;
	i = 0;
	while (i < 3)
	{
		next = ft_strchr(++next, '#');
		i2 = i * 2;
		piece->offsets[i2] =  ((next - input) % 5) - (first - input) % 5;
		i2 = i * 2 + 1;
		piece->offsets[i2] =  ((next - input) / 5) - (first - input) / 5;
		i++;
	}
}

void	ft_parse(char *input, t_piece *map, int tetri_nb)
{
	int i;
	int len;

	len = ft_strlen(input);
	i = 0;
	while (i < tetri_nb)
	{

		parse_piece(input, map + i);
		// parse a single piece into the map
		// move pointer along the correct amount making sure to stay in bounds
		/*
		if (boundcheck)
			input = input + 21?
		*/
		i++;
	}
}
