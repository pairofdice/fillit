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

#include "../libft/libft.h"
#include "fillit.h"

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
		piece->offsets[i2++] = ((next - input) % 5) - (first - input) % 5;
		piece->offsets[i2] = ((next - input) / 5) - (first - input) / 5;
		i++;
	}
}

int	ft_parse(char *input, t_piece **tetri_set, int tetri_nb)
{
	int		i;
	size_t	len;

	len = ft_strlen(input);
	i = 0;
	while (i < tetri_nb)
	{
		tetri_set[i] = malloc(sizeof(t_piece));
		if (!tetri_set[i])
			//delete all malloced pieces &
			return (1);
		parse_piece(input, tetri_set[i]);
		input = input + 21;
		i++;
	}
	return (0);
}
