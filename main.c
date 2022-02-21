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

#include "src/fillit.h"
#include "libft/libft.h"



int	main(int argc, char **argv)
{
	int		fd;
	ssize_t chr_count;
	int		tetri_nb;
	char	buff[BUFF + 1];

	tetri_nb = 0;
	if (argc != 2)
		return (write(1, "usage: ./fillit input_file\n", 28));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "error opening\n", 14));
	chr_count = read(fd, buff, BUFF + 1);
	buff[chr_count] = '\0';
	if (ft_isvalid(buff, chr_count, tetri_nb) != 1)
		return (write(1, "error\n", 6));
	else 
		return (write(1, "ok\n", 3));
//	ft_parse(buff);
	return (0);
}
