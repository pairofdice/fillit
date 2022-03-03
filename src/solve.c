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
//	printf("remove?\n");
//	printf("%s\n", *map);
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
	//	printf("%c piece removed\n", piece->name);
	}
	piece->placed = 0;
	return (1);
}

int	all_pieces_placed(t_piece **tetri_set, int tetri_nb)
{
	int	i;
//	printf("all pieces called?\n");

	i = 0;
	while (i < tetri_nb && tetri_set[i])
	{
//		printf("i is %d here\n", i);
//		printf("tetri_set i is %c", tetri_set[i]->name);
		if (tetri_set[i]->placed == 0)
		{
//				printf("all pieces 0\n");
			return (0);
		}
		i++;
	}
//	printf("all pieces 1\n");
	return (1);
}
int	ft_search(t_piece **tetri_set, char *map, int size, int tetri_nb, int i)
{
	int	j;

	j = 0;
//	printf("check 1\n");
	if (all_pieces_placed(tetri_set, tetri_nb) == 1)
		{
//			printf("all pieces called?\n");
			return (1);
		}
//	printf("check 2\n");
	while (map[j])
	{
			if (ft_place_piece(&map[j], tetri_set[i], size))
			{
//				printf("check 3\n");
				if (ft_search(tetri_set, map, size, tetri_nb, i + 1))
					return (1);
				ft_remove_piece(&map, tetri_set[i]);
			}

//		printf("%s\n\n", map);
		j++;
	}
	return (0);
}

/*int	ft_search(t_piece **tetri_set, char *map, int size, int tetri_nb)
{
	int	i;

	if (all_pieces_placed(tetri_set, tetri_nb) == 1)
		return (1);
	if (*map && *map != '.')
			return (ft_search(tetri_set, map + 1, size, tetri_nb));
	i = 0;
	while (i <= tetri_nb && tetri_set[i])
	{
		if (tetri_set[i]->placed || !ft_place_piece(map, tetri_set[i], size))
		{
			i++;
			continue ;
		}
		if (i < tetri_nb)
			tetri_set[i]->placed = 1;
		if (ft_search(tetri_set, map + 1, size, tetri_nb))
			return (1);
		ft_remove_piece(&map, tetri_set[i]);
		tetri_set[i]->placed = 0;
		i++;
	}
	return (0);
}*/

/*int	ft_search(t_piece **tetri_set, char *map, int size, int tetri_nb)
{
	int	i;

	if (all_pieces_placed(tetri_set, tetri_nb) == 1)
		return (1);
	if (*map && *map != '.')
			return (ft_search(tetri_set, map + 1, size, tetri_nb));
	i = 0;
	while (i <= tetri_nb && tetri_set[i])
	{
		if (tetri_set[i]->placed)
		{
			i++;
			continue ;
		}
		if (!ft_place_piece(map, tetri_set[i], size))
		{
			ft_search(tetri_set, map + 1, size, tetri_nb);
		}
		if (i < tetri_nb)
			tetri_set[i]->placed = 1;
		if (ft_search(tetri_set, map + 1, size, tetri_nb))
			return (1);
		ft_remove_piece(&map, tetri_set[i]);
		tetri_set[i]->placed = 0;
		i++;
	}
	return (0);
}*/

/*int	ft_search(t_piece **tetri_set, char *map, int size, int tetri_nb, int i)
{
//	int	i;

//	tetri_print(tetri_set, tetri_nb);
	printf("check 1 \n");
	if (all_pieces_placed(tetri_set, tetri_nb) == 1)
	{
//		printf("all pieces?\n");
		return (1);
	}
	printf("check 2 \n");
	if (*map && *map != '.')
		{
//			printf("map iterated\n");
			return (ft_search(tetri_set, map + 1, size, tetri_nb, i));
		}
//	i = 0;
	printf("check 3 \n");
	if (tetri_set[i]->placed)
		{
			ft_search(tetri_set, map, size, tetri_nb, i + 1);
//			printf("placed in search 2 %d\n", tetri_set[i]->placed);
		}
	printf("check 4 \n");
	while (*map)
//	while (i <= tetri_nb && tetri_set[i])
	{
		if (*map != '.')
		{
			map++;
			continue ;
		}
//		printf("%d <= %d \n", i, tetri_nb);
//		printf("placed in search 1 %d\n", tetri_set[i]->placed);
		if (!ft_place_piece(map, tetri_set[i], size))
		{
			map++;
			continue ;
		}
//		printf("placed in search 3 %d\n", tetri_set[i]->placed);
		if (i < tetri_nb)
			tetri_set[i]->placed = 1;
		if (ft_search(tetri_set, map, size, tetri_nb, i + 1))
			return (1);
		printf("trying to remove %c\n", tetri_set[i]->name);
//		printf("%s\n", map);
		ft_remove_piece(&map, tetri_set[i]);
		tetri_set[i]->placed = 0;
		map++;
	}
//	printf("failed to solve HERE\n");
	return (0);
}*/

int	solve(t_piece **tetri_set, int min_size, int tetri_nb)
{
	int		size;
	char	*map;
	char	*temp;

	//tetri_print(tetri_set, tetri_nb);
	size = min_size;
	if (!tetri_set)
		return (0);
	ft_map(size, &map);
	while (ft_search(tetri_set, map, size, tetri_nb, 0) == 0)
	{
		free(map);
		size++;
		ft_map(size, &map);
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
