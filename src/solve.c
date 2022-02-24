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
void	ft_solve()
{
	// left as an exercise for the reader
}

// Make the map
char	*ft_map(int size)
{
	char	*map;
	int		len;
	int		i;

	i = 0;
	len = (size + 1) * size + 1;
	map = malloc(sizeof(char) * (unsigned long)len);
	if (!map)
		return (NULL);
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
	printf("%s\n", map);
	return (map);
}


char	**solve(t_piece *input, int min_size);
{
	int		size;
    char	*map;

    size = min_size;
	// Make first map with min_size
    map = ft_map(size);
	// While solving is not successful size up, make new map and call again
    while (ft_solve(t_piece **tetri_set, char *map) != 1)
    {
		size++;
		ft_map(int size);
    }
	// Try to solve
	// if no solution found make the map bigger
}
