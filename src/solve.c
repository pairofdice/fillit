/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:43 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/23 16:57:07 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// TODO Functions to:

// Find a valid placement for a given piece
void	ft_next_valid_move(char **map_maybe, t_piece piece);
{
	// traverse cols, traverse rows
	// try to insert piece at each location checking bounds
	// if we find a spot return what? A pointer to a 1D array or x,y location in 2D array?
	// if we reach the end return NULL?
}

// Enter the piece into the map
void	ft_place_piece(char **map, t_piece piece)
{
	// check bounds
	// index into map using offsets
}

// remove a piece from the map
	// This could use ft_place_piece with piece name set to '.' or something

// Do the actual search for a solution
int	ft_solve()
{
	// left as an exercise for the reader
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
    while (ft_solve(tetri_set, map) != 1)
    {
		size++;
		ft_map(size, &map);
    }
	printf("%s\n", map);
	return (1);
}
