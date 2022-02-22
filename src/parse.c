/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:54:45 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/22 19:41:43 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// temp file
#include "../libft/libft.h"
#include "fillit.h"

void	parse_piece(char *input, t_piece *piece)
{
	int	i;
	char *first;
	char *next;

	first = ft_strchr(input, '#');
	next = first;
	i = 0;
	while (i < 3)
	{
		next = ft_strchr(++next, '#');
		piece->offsets[i * 2] =  ((next - input) % 5) - (first - input) % 5;
		piece->offsets[i * 2 + 1] =  ((next - input) / 5) - (first - input) / 5;
		i++;
	}
}
