/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:43 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/25 11:17:03 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// TODO Functions to:

// Enter the piece into the map
void	ft_place_piece(char **map, t_piece piece)
{
	// check bounds
	// index into map using offsets
}

// remove a piece from the map
	// This could use ft_place_piece with piece name set to '.' or something

// Do the actual search for a solution
int	ft_solve(t_piece **tetri_set, char **map)
{
	int i;

	if (all_pieces_placed)
		return (1);
	if (**map != '.')
		return (ft_solve(tetri_set, (*map)++));
	i = 0;
	while (tetri_set[i])
	{
		// place_piece needs to return 1 on success, 0 on fail
		if (!ft_place_piece(map, *tetri_set[i]))
		{
			i++;
			continue ;
		}
		// maybe just a field in the piece struct and all_pieces_placed
		// iterates through tetri_set?
		mark_piece_placed ;
		if (ft_solve(tetri_set,(*map)++))
			return (1);
		remove_piece();
		mark_piece_unplaced ;
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
