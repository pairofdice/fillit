/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:43 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/28 12:07:47 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// TODO Functions to:
// Enter the piece into the map
	// check bounds
	// index into map using offsets And check if all places free
		// if a place isn't free return 0
	// insert
	// return 1 on succesful insert

int ft_place_piece(char *map, t_piece *tetri_set, int size)
{

	if (*(map + tetri_set->offset[1] * (size + 1) + tetri_set->offset[0])
		&& *(map + tetri_set->offset[1] * (size + 1) + tetri_set->offset[0]) == '.'
		&& *(map + tetri_set->offset[3] * (size + 1) + tetri_set->offset[2])
		&& *(map + tetri_set->offset[3] * (size + 1) + tetri_set->offset[2]) == '.'
		&& *(map + tetri_set->offset[5] * (size + 1) + tetri_set->offset[4])
		&& *(map + tetri_set->offset[5] * (size + 1) + tetri_set->offset[4]) == '.'))
		{
			*map == *tetri_set->name;
			*(map + *tetri_set->offset[1] * (size + 1) + *tetri_set->offset[0]) == *tetri_set->name;
			*(map + *tetri_set->offset[3] * (size + 1) + *tetri_set->offset[2]) == *tetri_set->name;
			*(map + *tetri_set->offset[5] * (size + 1) + *tetri_set->offset[4]) == *tetri_set->name;
			return (1);
		}
	return (0);
}

/*int	ft_place_piece(char *map, char **loc, t_piece *piece)
{
	int	side;
	int k;

	side = ft_sqrt(ft_strlen(*map));
	k = 0;
	// check
	while (k < 3)
	{
		if (piece->offsets[k * 2] == occupied_by_another || OOB)
			return (0);
		if (piece->offsets[k * 2 + 1] == occupied_by_another || OOB)
			return (0);
		k++;
	}
	k = 0;
	while (k < 3)
	{
		// place
		k++;
	}

	return (1);
}*/

// remove a piece from the map
	// This could use ft_place_piece with piece name set to '.'???

int	all_pieces_placed(t_piece **tetri_set)
{
	int	i;

	i = 0;
	// need a null-terminated list?
	while (tetri_set[i])
	{
		if (tetri_set[i]->placed == 0)
			return (0);
		i++;
	}
	return (1);
}

// Do the actual depth-first-search for a solution
int	ft_solve(t_piece **tetri_set, char *map, int size)
{
	if (all_pieces_placed(tetri_set))
		return (1);
	if (*map != '.')
		return (ft_solve(tetri_set, ++map));
	i = placed;
	while (tetri_set[i])
	{
		if (!ft_place_piece(map, *tetri_set[i])) // FIX
		{
			i++;
			continue ;
		}
		tetri_set[i]->placed = 1;
		if (ft_solve(tetri_set, ++map, placed + 1))
			return (1);
		remove_piece();
		tetri_set[i]->placed = 0;
		i++;
	}
	return (0);
}

// Make the map
int	ft_map(int size, char **ptr)
{
	int		len;
	int		i;
	char	*map;

	i = 0;
	len = (size + 1) * size + 1;
	map = malloc(sizeof(char) * (unsigned long)len);
	if (!map)
		return (0);
	while (i < (len - 2))
	{
		if (i == size)
			map[i] = '\n';
		else if (i > size && (i + 1) % (size + 1) == 0)
			map[i] = '\n';
		else
			map[i] = '.';
		i++;
	}
	map[i] = '\0';
	*ptr = map;
	return (1);
}

/*int	ft_map(int size, char ***ptr)
{
	int	i;
	int	j;
	char	**map[size];

	i = 0;
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (unsigned long)size);
			if(!map[i])
			{
				while (--i)
				{
					free(map[i]);
					map[i] = NULL;
				}
			return (0);
			}
		j = 0;
		while (j < size)
		{
			*map[j] = '.'
			j++;
		}
		*map[j] = '\0';
		i++;
	}
	**ptr=map;
	return (1);
}*/

int	solve(t_piece **tetri_set, int min_size)
{
	int		size;
	char	*map;

	size = min_size;
	if (!tetri_set)
		return ;
	// Make first map with min_size
	ft_map(size, &map);
	// While solving is not successful size up, make new map and call again
	while (ft_solve(tetri_set, map, size) != 1)
	{
		size++;
		ft_map(size, &map);
	}
	ft_putstr(map);
	return (1);
}
