/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:49:04 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/23 13:29:42 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

# define BUFF 546
# define MAX_TETRI 26

typedef struct s_piece
{
	long	offsets [6];
	char	name;
	int		placed;
}	t_piece;

int		solve(t_piece **tetri_set, int min_size);
int		ft_isvalid(char **argv, char *buff, int *tetri_nb);
void	parse_piece(char *input, t_piece *piece);
int		ft_parse(char *input, t_piece **input_pieces, int tetri_nb);

#endif
