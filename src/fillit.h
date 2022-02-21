/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:49:04 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/21 13:56:01 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT-H 

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_piece
{
	int offsets [6];
	char name;
}	t_piece;

char	**solve(t_piece *input);

#endif
