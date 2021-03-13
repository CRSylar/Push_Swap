/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:58:40 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/13 13:37:11 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ra_loop(t_stack **tmp, t_stack *node)
{
	int	i;

	i = 0;
	while ((*tmp)->data != node->data)
	{
		ra(tmp);
		write(1, "ra\n", 3);
		i++;
	}
	return (i);
}

int			rra_loop(t_stack **tmp, t_stack *node)
{
	int		i;

	i = 0;
	while ((*tmp)->data != node->data)
	{
		rra(tmp);
		write(1, "rra\n", 4);
		i++;
	}
	return (i);
}

int			solve_easy(t_stack **tmp)
{
	t_stack *ptr;

	ptr = find_min(*tmp);
	if (stack_ordered(tmp))
		return (0);
	if (((*tmp)->data > (*tmp)->next->data) &&
		((*tmp)->data != ptr->data && (*tmp)->next->data != ptr->data))
	{
		ra(tmp);
		sa(tmp);
		write(1, "rra\nsa\n", 8);
		return (1);
	}
	if ((*tmp)->data == ptr->data && !stack_ordered(&((*tmp)->next)))
	{
		rra(tmp);
		sa(tmp);
		write(1, "ra\nsa\n", 8);
		return (1);
	}
	return (0);
}

t_stack		*find_min(t_stack *a)
{
	t_stack *min;
	int	i;

	i = 0;
	min = a;
	while (a)
	{
		if (a->data < min->data)
			min = a;
		a = a->next;
	}
	return (min);
}

int			solve_insertion_sort(t_stack **a)
{
	int				size;
	t_stack			*min;
	t_stack 		*tmp;
	t_stack			*b;
	int				c;

	tmp = *a;
	b = 0;
	size = ft_stack_size(tmp);
	while (size-- > 3)
	{
		min = find_min(tmp);
		c =	(min->pos < (size / 2)) ? ra_loop(&tmp, min) : rra_loop(&tmp, min);
		if (stack_ordered(&tmp))
			break ;
		pb(&tmp, &b);
		write(1, "pb\n", 3);
	}
	c += solve_easy(&tmp);
	size = ft_stack_size(b);
	while (size--)
	{
		pa(&tmp, &b);
		write(1, "pa\n", 3);
		c++;
	}
	return (c);
}
