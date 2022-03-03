/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:43 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/01 11:17:18 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_place_piece(char *map, t_piece *tetri, int size)
{
	int	first;
	int	second;
	int	third;

	first = (int)tetri->offset[1] * (size + 1) + (int)tetri->offset[0];
	second = (int)tetri->offset[3] * (size + 1) + (int)tetri->offset[2];
	third = (int)tetri->offset[5] * (size + 1) + (int)tetri->offset[4];
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

int	ft_remove_piece(char **map, t_piece *piece)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *map;
	if (*temp == 'x')
	{
		*temp = '.';
		return (1);
	}
	while (i < 4)
	{
		temp = ft_strchr(temp++, piece->name);
		*temp = '.';
		i++;
	}
	piece->placed = 0;
	return (1);
}

int	all_pieces_placed(t_piece **tetri_set, int tetri_nb)
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

int	ft_search(t_piece **tetri_set, char *map, int size, int tetri_nb, int i)
{
	int	j;

	j = 0;
	if (all_pieces_placed(tetri_set, tetri_nb) == 1)
		return (1);
	while (map[j])
	{
		if (ft_place_piece(&map[j], tetri_set[i], size))
		{
			if (ft_search(tetri_set, map, size, tetri_nb, i + 1))
				return (1);
			ft_remove_piece(&map, tetri_set[i]);
		}
		j++;
	}
	return (0);
}

int	solve(t_piece **tetri_set, int min_size, int tetri_nb)
{
	int		size;
	char	*map;
	char	*temp;

	size = min_size;
	if (!tetri_set)
		return (0);
	if (!ft_map(size, &map))
		return (0);
	while (ft_search(tetri_set, map, size, tetri_nb, 0) == 0)
	{
		free(map);
		size++;
		if (!ft_map(size, &map))
			return (0);
	}
	temp = map;
	while (*temp)
	{
		if (*temp == 'x')
			*temp = '.';
		temp++;
	}
	ft_putendl(map);
	return (1);
}
