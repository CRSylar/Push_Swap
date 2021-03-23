/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_visual.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:41:24 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/23 15:13:26 by cromalde         ###   ########.fr       */
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

int		check_input(char **av, t_stack **a);
int		close_win(t_win *win);
int		check(t_all *all);
int		find_max(t_stack *stack);
int		ft_stack_size(t_stack *stack);
int		read_inst(t_all *all);
void	my_mlx_pixel_put(t_all *all, int x, int y, int color);

#endif
