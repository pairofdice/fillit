/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:54:45 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/23 13:55:16 by jsaarine         ###   ########.fr       */
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
		piece->offsets[i2++] =  ((next - input) % 5) - (first - input) % 5;
		piece->offsets[i2] =  ((next - input) / 5) - (first - input) / 5;
		i++;
	}
}

int	ft_parse(char *input, t_piece **input_pieces, int tetri_nb)
{
	int		i;
	size_t	len;

	len = ft_strlen(input);
	i = 0;
	while (i < tetri_nb)
	{
		input_pieces[i] = malloc(sizeof(t_piece));
		if (!input_pieces[i])
			//delete all malloced pieces &
			return (1);
		parse_piece(input, input_pieces[i]);
		input = input + 21;
		i++;
	}
	return (0);
}

/*void	ft_parse(char *input, t_piece *input_pieces, int tetri_nb)
{
	int		i;
	size_t	len;

	len = ft_strlen(input);
	i = 0;
	if (tetri_nb)
	{}
	//while (i < tetri_nb)
	{

		parse_piece(input, input_pieces + i);
		input = input + 1;
		i++;
	}
}
*/