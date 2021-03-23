/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_visual.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:41:24 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/23 13:32:59 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_VISUAL_H
# define BONUS_VISUAL_H

# include <limits.h>
# include "instruction.h"
# include "checker.h"
# include "../minilibx_mms_20200219/mlx.h"

# define MAX(x,y) ((x > y) ? x : y)
# define ABS(x) ((x > 0) ? x : -x)
typedef struct	s_win
{
	void	*img;
	void	*mlx;
	void	*win;
}				t_win;

typedef struct	s_data
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_lgt;
	int		edn;
}				t_data;

typedef struct	s_all
{
	t_win			mlx;
	t_data			img;
	t_stack			*a;
	t_stack			*b;
	t_list			*istr;
	unsigned char	key;
}				t_all;



#endif
