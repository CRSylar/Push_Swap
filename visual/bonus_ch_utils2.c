/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ch_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:08:14 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/23 18:06:23 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_visual.h"

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

void	color_bk(t_all *all)
{
	int	w;
	int	h;

	h = 0;
	while (h < 901)
	{
		w = 0;
		while (w < 751)
		{
			if ((h > 30 && h < 870) &&
				((w >= 10 && w < 340) || (w >= 360 && w < 740)))
				my_mlx_pixel_put(all, w, h, 0x004F6F6F);
			else
				my_mlx_pixel_put(all, w, h, 0x001F2F2F);
			w++;
		}
		h++;
	}
	mlx_string_put(all->mlx.mlx, all->img.img, 175, 15, 0x4F6F6F, "A");
	mlx_string_put(all->mlx.mlx, all->img.img, 550, 15, 0x4F6F6F, "B");
}

void	print_loop(t_all *all, int max)
{
	all->img.img = mlx_new_image(all->mlx.mlx, 750, 900);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bpp,
							&all->img.line_lgt, &all->img.edn);
	color_bk(all);
	rend_stack(all->a, all, max, 'a');
	if (all->b)
		rend_stack(all->b, all, max, 'b');
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	mlx_do_sync(all->mlx.mlx);
	mlx_destroy_image(all->mlx.mlx, all->img.img);
}
