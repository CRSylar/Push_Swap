/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ch_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:06:37 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/23 15:20:23 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_visual.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->img.addr + (y * all->img.line_lgt + x * (all->img.bpp / 8));
	*(unsigned int*)dst = color;
}

int		close_win(t_win *win)
{
	int slp;

	slp = INT32_MAX;
	while (slp >= 0)
		slp--;
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
	return (1);
}

int		check(t_all *all)
{
	t_stack *tmp;

	tmp = all->a;
	while (tmp->next)
	{
		if (!(tmp->data < tmp->next->data))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		find_max(t_stack *stack)
{
	t_stack		*tmp;
	int			max;

	max = stack->data;
	tmp = stack;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int		ft_stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
