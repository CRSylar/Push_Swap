/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:33:28 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/23 13:41:22 by cromalde         ###   ########.fr       */
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

int		read_inst(t_all *all)
{
	int		ret;
	char	*line;

	line = 0;
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			return (ret);
		ft_lstadd_back(&(all->istr), ft_lstnew(line));
	}
	free(line);
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

int		check_input(char **av, t_stack **a)
{
	int			i;
	int			out;

	i = 1;
	while (av[i])
	{
		if (is_string(av[i]))
			string_handle(av[i], a);
		else
		{
			out = ft_atoi(av[i]);
			if (errno == 1)
				return (0);
			ft_push_stack(a, out);
		}
		i++;
	}
	if (check_duplicates(a))
		return (0);
	return (1);
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
