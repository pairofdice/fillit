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



void parse_pieces(char **input, t_piece *pieces, size_t num_pieces)
{
	 
}

int	ft_isvalid(char *buff, ssize_t chr_count)
{
	int	i;

	i = 0;
	printf("%zd\n", chr_count);
	printf("%s", buff);
	while (buff[i] != '\0')
	{
		if (buff[i] != '#' && buff[i] != '.' && buff[i] != '\n')
			return (0);
		if (buff[i] == '\n')
			if((i + 1) % 21 != 0)
				if ((i + 1) % 5 != 0)
					return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	ssize_t chr_count;
	char	buff[BUFF + 1];
	if (argc != 2)
		return (write(1, "usage: ./fillit input_file\n", 28));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "error opening\n", 14));
	chr_count = read(fd, buff, BUFF + 1);
	buff[chr_count] = '\0';
	if (ft_isvalid(buff, chr_count) != 1)
		return (write(1, "error\n", 6));
	else 
		return (write(1, "ok\n", 3));
//	ft_parse(buff);
	return (0);
}
