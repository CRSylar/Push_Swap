/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:33:28 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/23 15:11:56 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_visual.h"

void	end_visual(t_all *all)
{
	int	y;
	int	x;
	int	sol;

	sol = check(all);
	all->img.img = mlx_new_image(all->mlx.mlx, 750, 900);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bpp,
							&all->img.line_lgt, &all->img.edn);
	y = 0;
	while (y < 900)
	{
		x = 0;
		while (x < 750)
		{
			if (!sol)
				my_mlx_pixel_put(all, x, y, 0x002E8B57);
			else
				my_mlx_pixel_put(all, x, y, 0x00B22222);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	mlx_do_sync(all->mlx.mlx);
	mlx_destroy_image(all->mlx.mlx, all->img.img);
	ft_lstclear(&(all->istr), &free);
	close_win(&(all->mlx));
}

void	rend_stack(t_stack *stack, t_all *all, int max, char type)
{
	int			x;
	int			y;
	int			size;
	t_stack		*tmp;

	y = 50;
	size = ft_stack_size(stack);
	tmp = stack;
	while (tmp)
	{
		x = 0;
		if (type == 'a')
			while (x < ((((double)tmp->data / max) * 300) + 1))
			{
				my_mlx_pixel_put(all, x + 20, y, 0x00FF8C00);
				x++;
			}
		else
			while (x < ((((double)tmp->data / max) * 300) + 1))
			{
				my_mlx_pixel_put(all, x + 370, y, 0x00FFFACD);
				x++;
			}
		y += (850 / max);
		tmp = tmp->next;
	}
}

int		gui(t_all *all, int max)
{
	t_list *tmp;

	tmp = all->istr;
	if (!tmp)
		close_win(&(all->mlx));
	all->img.img = mlx_new_image(all->mlx.mlx, 750, 900);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bpp,
							&all->img.line_lgt, &all->img.edn);
	rend_stack(all->a, all, max, 'a');
	if (all->b)
		rend_stack(all->b, all, max, 'b');
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	mlx_do_sync(all->mlx.mlx);
	mlx_destroy_image(all->mlx.mlx, all->img.img);
	while (tmp)
	{
		if (find_command(tmp->content, &(all->a), &(all->b), 0) == -1)
		{
			write(2, "Error\n", 6);
			close_win(&(all->mlx));
			return (1);
		}
		tmp = tmp->next;
		all->img.img = mlx_new_image(all->mlx.mlx, 750, 900);
		all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bpp,
								&all->img.line_lgt, &all->img.edn);
		rend_stack(all->a, all, max, 'a');
		if (all->b)
			rend_stack(all->b, all, max, 'b');
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
		mlx_do_sync(all->mlx.mlx);
		mlx_destroy_image(all->mlx.mlx, all->img.img);
	}
	end_visual(all);
	return (0);
}

int		main(int ac, char **av)
{
	t_all	all;

	ft_bzero(&all, sizeof(t_all));
	if (ac < 3 && av)
		return (0);
	check_input(av, &(all.a));
	read_inst(&all);
	all.mlx.mlx = mlx_init();
	all.mlx.win = mlx_new_window(all.mlx.mlx, 750, 900, "PUSH SWAP VISUALIZER");
	mlx_hook(all.mlx.win, 17, 1l << 2, &close_win, &all);
	gui(&all, find_max(all.a));
	mlx_loop(all.mlx.mlx);
}
