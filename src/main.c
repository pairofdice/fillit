/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:51:32 by ncsomori          #+#    #+#             */
/*   Updated: 2022/03/04 11:01:14 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_sqrt(int nb)
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
	t_state	state;
	t_piece	*tetri_set[MAX_TETRI + 1];
	char	buff[BUFF + 1];

	state.tetri_nb = 0;
	if (argc != 2)
		return ((int)write(1, "usage: ./fillit input_file\n", 28));
	if (ft_isvalid(argv, buff, &state) != 1)
		return ((int)write(1, "error\n", 6));
	state.size = ft_sqrt(state.tetri_nb * 4);
	if (ft_parse(buff, tetri_set, state.tetri_nb) != 0)
		return ((int)write(1, "error\n", 6));
	if (solve(tetri_set, &state) == 0)
		return ((int)write(1, "error\n", 6));
	return (0);
}
