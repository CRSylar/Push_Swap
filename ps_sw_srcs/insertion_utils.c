/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:36:14 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/19 19:09:27 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ra_loop(t_stack **tmp, int count)
{
	int	i;

	i = 0;
	while (count--)
	{
		ra(tmp, 0);
		write(1, "ra\n", 3);
		i++;
	}
	return (i);
}

int			rra_loop(t_stack **tmp, int count)
{
	int		i;

	i = 0;
	while (count--)
	{
		rra(tmp, 0);
		write(1, "rra\n", 4);
		i++;
	}
	return (i);
}

int			find_min(t_stack *a)
{
	int	index;
	int	min;
	int	i;

	i = 0;
	index = 0;
	min = a->data;
	while (a)
	{
		if (a->data < min)
		{
			min = a->data;
			index = i;
		}
		a = a->next;
		i++;
	}
	return (index);
}
