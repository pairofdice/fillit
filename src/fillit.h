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

typedef struct s_piece
{
	long		offsets [6];
	char	name;
}	t_piece;

char	**solve(t_piece *input);
int		ft_isvalid(char **argv, char *buff, int tetri_nb);
void	parse_piece(char *input, t_piece *piece);
void	ft_parse(char *input, t_piece *input_pieces, int tetri_nb);

#endif
