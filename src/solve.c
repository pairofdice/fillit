/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:43 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/08 17:05:53 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <string.h>
#include <stdio.h>

static int	ft_place_piece(char *map, t_piece *tetri, int size, int j)
{
	int	first;
	int	second;
	int	third;
	int	len;

	first = (int)tetri->offset[1] * (size + 1) + (int)tetri->offset[0];
	second = (int)tetri->offset[3] * (size + 1) + (int)tetri->offset[2];
	third = (int)tetri->offset[5] * (size + 1) + (int)tetri->offset[4];
 	len = (size + 1) * (size) - j - 1;
	if (len < first || len < second || len < third)
		return (0);
	if (*map && *map == '.'
		&& *(map + first) && *(map + first) == '.'
		&& *(map + second) && *(map + second) == '.'
		&& *(map + third) && *(map + third) == '.')
	{
		*map = tetri->name;
		*(map + first) = tetri->name;
		*(map + second) = tetri->name;
		*(map + third) = tetri->name;
		tetri->placed = 1;
		return (1);
	}
	return (0);
}

static int	ft_remove_piece(char **map, t_piece *piece)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *map;
	while (i < 4)
	{
		temp = ft_strchr(temp++, piece->name);
		*temp = '.';
		i++;
	}
	piece->placed = 0;
	return (1);
}

static int	all_pieces_placed(t_piece **tetri_set, int tetri_nb)
{
	int	i;

	i = 0;
	while (i < tetri_nb && tetri_set[i])
	{
		if (tetri_set[i]->placed == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_search(t_piece **tetri_set, char *map, t_state *state, int i)
{
	int	j;
	//int len;

	j = 0;
	if (all_pieces_placed(tetri_set, state->tetri_nb) == 1)
		return (1);
	while (map[j])
	{
		while (map[j] != '.' && j < state->len)
			j++;
		if (ft_place_piece(&map[j], tetri_set[i], state->size, j))
		{
			if (ft_search(tetri_set, map, state, i + 1))
				return (1);
			ft_remove_piece(&map, tetri_set[i]);
		}
		j++;
	}
	return (0);
}

int	solve(t_piece **tetri_set, t_state *state)
{
	char	*map;

	if (!tetri_set)
		return (0);
	if (!ft_map(state->size, &map))
		return (0);
	while (ft_search(tetri_set, map, state, 0) == 0)
	{
		free(map);
		state->size++;
		state->len = (state->size + 1) * (state->size) - 2;
		if (!ft_map(state->size, &map))
			return (0);
	}
	ft_putendl(map);
	free(map);
	ft_delete_tetri(tetri_set, state->tetri_nb - 1);
	return (1);
}
