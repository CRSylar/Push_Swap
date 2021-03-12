/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:58:40 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/12 19:45:24 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_loop(t_stack **tmp, int count)
{
	while (count)
	{
		ra(tmp);
		write(1, "ra\n", 3);
		count--;
	}
}

void	rra_loop(t_stack **tmp, int count)
{
	while (count)
	{
		rra(tmp);
		write(1, "rra\n", 4);
		count++;
	}
}

int		find_min(t_stack *a, int size)
{
	int min;
	int	i;

	i = 0;
	min = a->data;
	while (a)
	{
		if (a->data < min)
		{
			min = a->data;
			i++;
		}
		a = a->next;
	}
	if (i < (size / 2))
		return(i);
	return (-i);
}

int		solve_insertion_sort(t_stack **a)
{
	int				count;
	int				size;
	t_stack 		*tmp;
	static t_stack	*b;

	tmp = *a;
	size = ft_stack_size(tmp);
	count = find_min(tmp, size);
	(count > 0) ? ra_loop(&tmp, count) : rra_loop(&tmp, count);
	pb(&tmp, &b);
	write(1, "pb\n", 3);
	return (1);
}
