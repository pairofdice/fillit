/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:49:04 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/08 17:04:24 by jsaarine         ###   ########.fr       */
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
	long	offset [6];
	char	name;
	int		placed;
}	t_piece;

typedef struct s_state
{
	int	size;
	int	tetri_nb;
	int len;
}	t_state;

int		ft_map(int size, char **ptr);
int		ft_isvalid(char **argv, char *buff, t_state *state);
int		ft_parse(char *input, t_piece **tetri_set, int tetri_nb);
int		solve(t_piece **tetri_set, t_state *state);
int		ft_delete_tetri(t_piece **tetri_set, int i);

#endif
