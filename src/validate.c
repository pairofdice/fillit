/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:31:11 by ncsomori          #+#    #+#             */
/*   Updated: 2022/02/22 12:15:09 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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

int	ft_isvalid(char *buff, ssize_t chr_count, int tetri_nb)
{
	int	i;

	i = 0;
	if (buff[i] == '\0')
		return (0);
	while (i < chr_count)
	{
		if (ft_chrcount(buff + i) != 1)
			return (0);
		if (ft_adjpart(buff + i) != 1)
			return (0);
		i += 21;
		tetri_nb++;
	}
	return (1);
}
