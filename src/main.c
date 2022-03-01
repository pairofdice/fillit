/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:51:32 by ncsomori          #+#    #+#             */
/*   Updated: 2022/02/25 12:30:47 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
/*
void	print_map(char **map)
{
	int	side;
	int	i;

	side = ft_sqrt(ft_strlen(*map));
	while (**map)
	{
		i = 0;
		while (i < side)
		{
			ft_putchar((*map)++);
			(*map)++;
			i++;
		}
		ft_putchar('\n');
	}
}*/

void	tetri_print(t_piece **tetri_set, int tetri_nb)
{
	int	i;
	int	j;

	i = 0;
	while (i <= tetri_nb)
	{
		j = -1;
		printf("Name is %c\n", tetri_set[i]->name);
		while (j++ < 5)
		{
			printf("Offset %d is %ld\n", j, tetri_set[i]->offset[j]);
		}
		i++;
	}
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i) <= nb)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (i);
}

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

int	main(int argc, char **argv)
{
	int		tetri_nb;
	int		min_size;
	t_piece	*tetri_set[MAX_TETRI + 1];
//	t_piece	**tetri_set;
	char	buff[BUFF + 1];

	tetri_nb = 0;
	if (argc != 2)
		return ((int)write(1, "usage: ./fillit input_file\n", 28));
	if (ft_isvalid(argv, buff, &tetri_nb) != 1)
		return ((int)write(1, "error\n", 6));
//	tetri_set = (t_piece**)malloc(sizeof(t_piece*) * ((unsigned long)tetri_nb + 1));
	ft_putstr("validation done\n");
	min_size = ft_sqrt(tetri_nb * 4);
	if (ft_parse(buff, tetri_set, tetri_nb) != 0)
		return ((int)write(1, "error\n", 6));
//	tetri_print(tetri_set);
	ft_putstr("parsing done\n");
	tetri_print(tetri_set, tetri_nb);
	tetri_set[tetri_nb]->name = '@';
	tetri_print(tetri_set, tetri_nb);
	printf("test\n");
	if (solve(tetri_set, min_size, tetri_nb) == 0)
		return ((int)write(1, "error\n", 6));
	return (0);
}
