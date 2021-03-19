/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:58:40 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/19 19:08:11 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int			solve_easy_2(t_stack **tmp)
{
	int i;

	i = 0;
	if (((*tmp)->data > (*tmp)->next->data) &&
		stack_ordered(&((*tmp)->next)))
	{
		if ((*tmp)->data < (*tmp)->next->next->data)
		{
			sa(tmp, 0);
			write(1, "sa\n", 3);
			return (++i);
		}
		ra(tmp, 0);
		write(1, "ra\n", 3);
		return (++i);
	}
	else if (((*tmp)->data < (*tmp)->next->data) &&
		!stack_ordered(&((*tmp)->next)))
	{
		rra(tmp, 0);
		sa(tmp, 0);
		write(1, "rra\nsa\n", 7);
		i += 2;
	}
	return (i);
}

static	int			solve_easy_1(t_stack **tmp)
{
	int ret;

	if (stack_ordered(tmp))
		return (0);
	if ((((*tmp)->data > (*tmp)->next->data)) &&
		((*tmp)->next->data > (*tmp)->next->next->data))
	{
		ra(tmp, 0);
		sa(tmp, 0);
		write(1, "ra\nsa\n", 6);
		return (2);
	}
	else if ((*tmp)->data < (*tmp)->next->data &&
		(*tmp)->data > (*tmp)->next->next->data)
	{
		rra(tmp, 0);
		write(1, "rra\n", 4);
		return (1);
	}
	ret = solve_easy_2(tmp);
	return (ret);
}

static	int			clean_b(t_stack **tmp, t_stack **b)
{
	int	size;
	int	c;

	c = 0;
	size = ft_stack_size(*b);
	while (size)
	{
		pa(tmp, b, 0);
		write(1, "pa\n", 3);
		c++;
		size--;
	}
	free_stack(b);
	return (c);
}

int					solve_insertion_sort(t_stack **a)
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
	while (size > 3 && ++c)
	{
		min = find_min(tmp);
		c += (min < (size / 2)) ? ra_loop(&tmp, min) : rra_loop(&tmp, size - min);
		if (stack_ordered(&tmp))
			break ;
		pb(&tmp, &b, 0);
		write(1, "pb\n", 3);
		size--;
	}
	c += solve_easy_1(&tmp) + clean_b(&tmp, &b);
	return (c);
}
