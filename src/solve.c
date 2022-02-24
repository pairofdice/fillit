/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:43 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/24 12:30:23 by jsaarine         ###   ########.fr       */
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
	next = ft_next_valid_move(tetri_set, map);
	if (!next)
		return (0);
	while (tetri_set)
	{
		
	}
}

// Resize map
void ft_map_resize(char **map)
{
	// ...
}


char	**solve(t_piece *input);
{
	// Try to solve
	// if no solution found make the map bigger
}
