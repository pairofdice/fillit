/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:31:11 by ncsomori          #+#    #+#             */
/*   Updated: 2022/02/22 19:55:38 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_chrcount(char *buff)
{
	int	i;
	int	piece;

	i = 0;
	piece = 0;
	while (i < 19 && buff[i])
	{
		if (buff[i] != '#' && buff[i] != '.' && buff[i] != '\n')
			return (0);
		if (buff[i] == '\n' && (i + 1) % 5 != 0)
			return (0);
		if (buff[i] == '#')
			piece++;
		i++;
	}
	if (!buff[i] || piece != 4 || (buff[i] != '\n' && buff[i] != '\0'))
		return (0);
	return (1);
}

int	ft_adjpart(char *buff)
{
	int	i;
	int	connection;

	i = 0;
	connection = 0;
	while (i < 19)
	{
		if (buff[i] == '#')
		{
			if (i - 1 >= 0 && buff[i - 1] == '#')
				connection++;
			if (i + 1 <= 19 && buff[i + 1] == '#')
				connection++;
			if (i - 5 >= 0 && buff[i - 5] == '#')
				connection++;
			if (i + 5 <= 19 && buff[i + 5] == '#')
				connection++;
		}
		i++;
	}
	if (connection != 6 && connection != 8)
		return (0);
	return (1);
}

int	ft_isvalid(char **argv, char *buff, int *tetri_nb)
{
	int		i;
	int		fd;
	ssize_t	chr_count;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	chr_count = read(fd, buff, BUFF + 1);
	buff[chr_count] = '\0';
	close(fd);
	if (buff[chr_count - 1] == '\n' && buff[chr_count - 2] == '\n')
		return (0);
	if (buff[i] == '\0')
		return (0);
	while (i < chr_count)
	{
		if (ft_chrcount(buff + i) != 1)
			return (0);
		if (ft_adjpart(buff + i) != 1)
			return (0);
		i += 21;
		(*tetri_nb)++;
	}
	return (1);
}
