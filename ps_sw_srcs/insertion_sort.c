/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:58:40 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/14 10:26:40 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			solve_easy_2(t_stack **tmp)
{
	int i;

	i = 0;
	if (((*tmp)->data > (*tmp)->next->data) &&
		stack_ordered(&((*tmp)->next)))
	{
		if ((*tmp)->data < (*tmp)->next->next->data)
		{
			sa(tmp);
			write(1, "sa\n", 3);
			i++;
		}
		ra(tmp);
		write(1, "ra\n", 3);
		return (++i);
	}
	else if (((*tmp)->data < (*tmp)->next->data) &&
		!stack_ordered(&((*tmp)->next)))
	{
		rra(tmp);
		sa(tmp);
		write(1, "rra\nsa\n", 7);
		i += 2;
	}
	return (i);
}

int			solve_easy_1(t_stack **tmp)
{
	int ret;

	if (stack_ordered(tmp))
		return (0);
	if ((((*tmp)->data > (*tmp)->next->data)) &&
		((*tmp)->next->data > (*tmp)->next->next->data))
	{
		ra(tmp);
		sa(tmp);
		write(1, "ra\nsa\n", 7);
		return (2);
	}
	else if ((*tmp)->data < (*tmp)->next->data &&
		(*tmp)->data > (*tmp)->next->next->data)
	{
		rra(tmp);
		write(1, "rra\n", 4);
		return (1);
	}
	ret = solve_easy_2(tmp);
	return (ret);
}

int			clean_b(t_stack *tmp, t_stack *b)
{
	int	size;
	int	c;

	c = 0;
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

int			solve_insertion_sort(t_stack **a)
{
	int				size;
	int				min;
	t_stack			*tmp;
	t_stack			*b;
	int				c;

	tmp = *a;
	b = 0;
	c = 0;
	size = ft_stack_size(tmp);
	while (size > 3)
	{
		min = find_min(tmp);
		c += (min < (size / 2)) ? ra_loop(&tmp, min) :
			rra_loop(&tmp, size - min);
		if (stack_ordered(&tmp))
			break ;
		pb(&tmp, &b);
		write(1, "pb\n", 3);
		size--;
		c++;
	}
	c += solve_easy_1(&tmp) + clean_b(tmp, b);
	return (c);
}
