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
#include <stdio.h>

// Enter the piece into the map
	// check bounds
	// index into map using offsets And check if all places free
		// if a place isn't free return 0
	// insert
	// return 1 on succesful insert

int ft_place_piece(char *map, t_piece *tetri, int size)
{
	int first;
	int second;
	int third;

	first = (int)tetri->offset[1] * (size + 1) + (int)tetri->offset[0];
	second = (int)tetri->offset[3] * (size + 1) + (int)tetri->offset[2];
	third = (int)tetri->offset[5] * (size + 1) + (int)tetri->offset[4];
	if (*(map + first) && *(map + first) == '.' 
		&& *(map + second) && *(map + second) == '.'
		&& *(map + third) && *(map + third) == '.')
		{
			*map = tetri->name;
			*(map + first) = tetri->name;
			*(map + second) = tetri->name;
			*(map + third) = tetri->name;
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
int	ft_remove_piece(char **map, t_piece *piece)
{
	int i;
	char *temp;

	i = 0;
	temp = *map;
	while (i < 4)
	{
		temp = ft_strchr(temp++, piece->name);
		temp =  ".";
	}
	return (1);
}

int	all_pieces_placed(t_piece **tetri_set)
{
	int	i;
	int count = 0;

	i = 0;
	while (tetri_set[i])
	{
		if (tetri_set[i]->placed == 0)
			{
				printf("placed 0\n");
				return (0);
			}
		count++;
		printf("palced: %d", count);
		i++;
	}
	return (1);
}

int    ft_search(t_piece **tetri_set, char *map, int size)
{
    int i;

    if (all_pieces_placed(tetri_set))
        return (1);
    if (*map != '.')
        return (ft_search(tetri_set, ++map, size));
    i = 0;
    while (tetri_set[i])
    {
        if (tetri_set[i]->placed || !ft_place_piece(map, tetri_set[i], size))
        {
            i++;
            continue ;
        }
        tetri_set[i]->placed = 1;
        if (ft_search(tetri_set, ++map, size))
            return (1);
        ft_remove_piece(&map, tetri_set[i]);
        tetri_set[i]->placed = 0;
        i++;
    }
    return (0);
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
	int		solved;
	char	*map;
	int		i;

	i = 0;
	solved = 0;
	size = min_size;
	if (!tetri_set)
		return (0);
	ft_map(size, &map);
	printf("size is %d\n", size);
	while (ft_search(tetri_set, map, size) != 1)
	{
		size++;
		ft_map(size, &map);
		printf("map resized\n");
	}
	ft_putstr(map);
	return (1);
}
