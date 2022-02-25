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

int	main(int argc, char **argv)
{
	int		tetri_nb;
	int		min_size;
	t_piece	*tetri_set[MAX_TETRI];
	char	buff[BUFF + 1];

	tetri_nb = 0;
	if (argc != 2)
		return ((int)write(1, "usage: ./fillit input_file\n", 28));
	if (ft_isvalid(argv, buff, &tetri_nb) != 1)
		return ((int)write(1, "error\n", 6));
	min_size = ft_sqrt(tetri_nb * 4);
	if (ft_parse(buff, tetri_set, tetri_nb) != 0)
		return ((int)write(1, "error\n", 6));
	solve(tetri_set, min_size);
	return (0);
}
