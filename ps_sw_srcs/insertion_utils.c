/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:36:14 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/23 16:35:04 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ra_loop(t_stack **tmp, int count, char flag)
{
	int	i;

	i = 0;
	while (count--)
	{
		ra(tmp, flag);
		i++;
	}
	return (i);
}

int			rra_loop(t_stack **tmp, int count, char flag)
{
	int		i;

	i = 0;
	while (count--)
	{
		rra(tmp, flag);
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

int			solve5_2(t_stack **a, t_stack **b, char flag)
{
	pb(a, b, flag);
	rra(a, flag);
	pb(a, b, flag);
	sa(a, flag);
	pa(a, b, flag);
	pa(a, b, flag);
	ra(a, flag);
	ra(a, flag);
	return (8);
}

int			solve5(t_stack **a, t_stack **b, char flag)
{
	pb(a, b, flag);
	pb(a, b, flag);
	ss(a, b, flag);
	ra(a, flag);
	pa(a, b, flag);
	sa(a, flag);
	pa(a, b, flag);
	rra(a, flag);
	return (8);
}
