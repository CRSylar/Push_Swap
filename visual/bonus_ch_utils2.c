/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ch_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:08:14 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/23 15:11:32 by cromalde         ###   ########.fr       */
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
