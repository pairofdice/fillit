/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:54:45 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/25 11:33:55 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_delete_tetri(t_piece **tetri_set, int i)
{
	if (i > 0)
	{
		while (--i)
		{
			free(tetri_set[i]);
			*tetri_set = NULL;
		}
	}
	return (1);
}

void	parse_piece(char *input, t_piece *piece)
{
	int		i;
	int		i2;
	char	*first;
	char	*next;

	first = ft_strchr(input, '#');
	next = first;
	i = 0;
	while (i < 3)
	{
		next = ft_strchr(++next, '#');
		i2 = i * 2;
		piece->offset[i2++] = ((next - input) % 5) - (first - input) % 5;
		piece->offset[i2] = ((next - input) / 5) - (first - input) / 5;
		i++;
	}
}

int	ft_parse(char *input, t_piece **tetri_set, int tetri_nb)
{
	int		i;

	i = -1;
	while (++i < tetri_nb)
	{
		tetri_set[i] = malloc(sizeof(t_piece));
		if (!tetri_set[i])
			return (ft_delete_tetri(tetri_set, i));
		tetri_set[i]->name = (char)('A' + i);
		parse_piece(input, tetri_set[i]);
		input = input + 21;
	}
	return (0);
}
