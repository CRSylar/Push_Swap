/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:58:40 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/13 17:21:39 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ra_loop(t_stack **tmp, int count)
{
	int	i;

	i = 0;
	while (count--)
	{
		ra(tmp);
		write(1, "ra\n", 3);
		i++;
	}
	return (i);
}

int			rra_loop(t_stack **tmp, int	count)
{
	int		i;

	i = 0;
	while (count--)
	{
		rra(tmp);
		write(1, "rra\n", 4);
		i++;
	}
	return (i);
}

int			solve_easy(t_stack **tmp)
{

	if (stack_ordered(tmp))
		return (0);
	if ((((*tmp)->data > (*tmp)->next->data)) &&
		((*tmp)->next->data > (*tmp)->next->next->data))
	{
		ra(tmp);
		sa(tmp);
		write(1, "ra\nsa\n", 7);
		return (1);
	}
	else if (((*tmp)->data < (*tmp)->next->data) &&
		!stack_ordered(&((*tmp)->next)))
	{
		rra(tmp);
		sa(tmp);
		write(1, "rra\nsa\n", 6);
		return (2);
	}
	else  if (((*tmp)->data > (*tmp)->next->data) &&
		stack_ordered(&((*tmp)->next)))
	{
		if ((*tmp)->data < (*tmp)->next->next->data)
		{
			sa(tmp);
			write(1, "sa\n", 3);
		}
		ra(tmp);
		write(1, "ra\n", 3);
		return (1);
	}
	return (0);
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

int			solve_insertion_sort(t_stack **a)
{
	int				size;
	int				min;
	t_stack 		*tmp;
	t_stack			*b;
	int				c;

	tmp = *a;
	b = 0;
	size = ft_stack_size(tmp);
	while (size > 3)
	{
		min = find_min(tmp);
		c =	(min < (size / 2)) ? ra_loop(&tmp, min) : rra_loop(&tmp, size - min);
		if (stack_ordered(&tmp))
			break ;
		pb(&tmp, &b);
		write(1, "pb\n", 3);
		size--;
	}
	c += solve_easy(&tmp);
	size = ft_stack_size(b);
	while (size)
	{
		pa(&tmp, &b);
		write(1, "pa\n", 3);
		c++;
		size--;
	}
	return (c);
}
