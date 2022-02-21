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
#include "libft/libft.h"

int	ft_chrcount(char *buff)
{
	int	i;
	int piece;

	i = 0;
	piece = 0;
	while (i < 19)
	{
		if (buff[i] != '#' && buff[i] != '.' && buff[i] != '\n')
			return (0);
		if (buff[i] == '\n' && (i + 1) % 5 != 0)
			return (0);
		if (buff[i] == '#')
			piece++;
		i++;
	}
	if (!buff[i] || buff[i] != '\n' || piece != 4)
		return (0);
	return (1);
}

int	ft_adjpart(char *buff)
{
	int	i;
	int	connection;

	i = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			if (i % 5 == 0 && buff[i + 1] )

		}
	i++;
	}
	return (1);
}

int	ft_isvalid(char *buff, ssize_t chr_count, int tetri_nb)
{
	int i;

	i = 0;
	while (i < chr_count)
	{
		if (ft_chrcount(buff + i) != 1)
			return (0);
		ft_adjpart(buff + i);
		i += 21;
		tetri_nb++;
	}
	return (1);
}

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
