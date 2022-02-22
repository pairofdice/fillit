/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:51:32 by ncsomori          #+#    #+#             */
/*   Updated: 2022/02/21 11:54:26 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		tetri_nb;
//	t_piece *tetri_set[MAX_TETRI];
	char	buff[BUFF + 1];

	tetri_nb = 0;
	if (argc != 2)
		return ((int)write(1, "usage: ./fillit input_file\n", 28));
	if (ft_isvalid(argv, buff, tetri_nb) != 1)
		return ((int)write(1, "error\n", 6));
	else
		return ((int)write(1, "ok\n", 3));
//	ft_parse(buff);
//	ft_solve()
	return (0);
}
