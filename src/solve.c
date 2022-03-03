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

	printf("Map got: \n%s\n", map);
	printf("%c\n", tetri->name);
	ft_putstr("in the place_piece\n");
	first = (int)tetri->offset[1] * (size + 1) + (int)tetri->offset[0];
	second = (int)tetri->offset[3] * (size + 1) + (int)tetri->offset[2];
	third = (int)tetri->offset[5] * (size + 1) + (int)tetri->offset[4];
	printf("offset calculated\n");
/*	printf("first is %d\n", first);
	printf("second is %d\n", second);
	printf("third is %d\n", third);
	printf("first char is %c\n", *(map + first));
	printf("second char is %c\n", *(map + second));
	printf("third char is %c\n", *(map + third));*/
	if (*(map + first) && *(map + first) == '.'
		&& *(map + second) && *(map + second) == '.'
		&& *(map + third) && *(map + third) == '.')
	{
		*map = tetri->name;
		*(map + first) = tetri->name;
		*(map + second) = tetri->name;
		*(map + third) = tetri->name;
//		printf("should print map here\n");
//		ft_putendl(map);
		return (1);
	}
//	ft_putendl(map);
//	printf("gives 0 back\n");
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
//		printf("removed a piece \n");
		return (1);
	}
	while (i < 4)
	{
		temp = ft_strchr(temp++, piece->name);
		*temp = '.';
		i++;
	}
//	printf("removed a piece \n");
	return (1);
}

int	all_pieces_placed(t_piece **tetri_set, int tetri_nb)
{
	int	i;

	i = 0;
//	printf("all pieces? \n");
	while (i < tetri_nb && tetri_set[i])
	{
		if (tetri_set[i]->placed == 0)
			return (0);
		i++;
	}
//	tetri_print(tetri_set, tetri_nb);
	return (1);
}

int	ft_search(t_piece **tetri_set, char *map, int size, int tetri_nb)
{
	int	i;

//	tetri_print(tetri_set, tetri_nb);
//	printf("check 1 \n");
	if (all_pieces_placed(tetri_set, tetri_nb) == 1)
	{
//		printf("all pieces?\n");
		return (1);
	}
//	printf("check 2 \n");
	if (*map && *map != '.')
		{
//			printf("map iterated\n");
			return (ft_search(tetri_set, map + 1, size, tetri_nb));
		}
	i = 0;
	printf("check 3 \n");
	while (i <= tetri_nb && tetri_set[i])
	{
//		printf("%d <= %d \n", i, tetri_nb);
//		printf("placed in search 1 %d\n", tetri_set[i]->placed);
		if (tetri_set[i]->placed || !ft_place_piece(map, tetri_set[i], size))
		{
//			printf("placed in search 2 %d\n", tetri_set[i]->placed);
			i++;
			continue ;
		}
//		printf("placed in search 3 %d\n", tetri_set[i]->placed);
		if (i < tetri_nb)
			tetri_set[i]->placed = 1;
		if (ft_search(tetri_set, map + 1, size, tetri_nb))
			return (1);
//		printf("trying to remove %d\n", i);
//		printf("%s\n", map);
		ft_remove_piece(&map, tetri_set[i]);
		tetri_set[i]->placed = 0;
		i++;
	}
//	printf("failed to solve HERE\n");
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
	ft_map(size, &map);
	while (ft_search(tetri_set, map, size, tetri_nb) == 0)
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
