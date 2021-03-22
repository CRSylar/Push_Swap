/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:33:28 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/22 18:42:15 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_visual.h"

void	ft_push_stack(t_stack **a, int out)
{
	t_stack *new;
	t_stack *tmp;

	new = malloc(sizeof(t_stack));
	new->data = out;
	new->next = 0;
	if (!*a)
	{
		*a = new;
		return ;
	}
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->img.addr + (y * all->img.line_lgt + x * (all->img.bpp / 8));
	*(unsigned int*)dst = color;
}

int		close_win(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
	return (1);
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

void	rend_stack(t_stack *stack, t_all *all, char type)
{
	int			max;
	int			x;
	int			y;
	t_stack		*tmp;

	y = 20;
	max = find_max(stack);
	tmp = stack;
	while (tmp)
	{
		x = 20;
		if (type == 'a')
			my_mlx_pixel_put(all, x, y, 0x00FF8C00);
		else
			my_mlx_pixel_put(all, x + 350, y, 0x00FFFACD);
		y += 30;
		tmp = tmp->next;
	}
}

int		gui(t_all *all)
{
	rend_stack(all->a, all, 'a');
//	if (all->b)
//		rend_stack(all->b, all,  'b');
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
//	read_inst(all);
//	ft_lstclear(&(all->istr), &free);
	return (1);
}

int		check_duplicates(t_stack **a)
{
	t_stack *tmp;
	t_stack	*tmp2;

	tmp = *a;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp->next->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
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
	all.mlx.mlx = mlx_init();
	all.mlx.win = mlx_new_window(all.mlx.mlx, 700, 700, "PUSH SWAP VISUALIZER");
	all.img.img = mlx_new_image(all.mlx.mlx, 700, 700);
	all.img.addr = mlx_get_data_addr(all.img.img, &all.img.bpp,
								&all.img.line_lgt, &all.img.edn);
	check_input(av, &(all.a));
	mlx_hook(all.mlx.win, 17, 1l << 2, &close_win, &all);
	mlx_loop_hook(all.mlx.mlx, &gui, &all);
	mlx_loop(all.mlx.mlx);
}
