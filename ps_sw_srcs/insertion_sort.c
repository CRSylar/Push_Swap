/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:58:40 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/23 16:35:47 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int					solve_easy_2(t_stack **tmp, char flag)
{
	int i;

	i = 0;
	if (((*tmp)->data > (*tmp)->next->data) &&
		stack_ordered(&((*tmp)->next)))
	{
		if ((*tmp)->data < (*tmp)->next->next->data)
		{
			sa(tmp, flag);
			return (++i);
		}
		ra(tmp, flag);
		return (++i);
	}
	else if (((*tmp)->data < (*tmp)->next->data) &&
		!stack_ordered(&((*tmp)->next)))
	{
		rra(tmp, flag);
		sa(tmp, flag);
		i += 2;
	}
	return (i);
}

int					solve_easy_1(t_stack **tmp, char flag)
{
	int ret;

	if (stack_ordered(tmp))
		return (0);
	if ((((*tmp)->data > (*tmp)->next->data)) &&
		((*tmp)->next->data > (*tmp)->next->next->data))
	{
		ra(tmp, flag);
		sa(tmp, flag);
		return (2);
	}
	else if ((*tmp)->data < (*tmp)->next->data &&
		(*tmp)->data > (*tmp)->next->next->data)
	{
		rra(tmp, flag);
		return (1);
	}
	ret = solve_easy_2(tmp, flag);
	return (ret);
}

static	int			clean_b(t_stack **tmp, t_stack **b, char flag)
{
	int	size;
	int	c;

	c = 0;
	size = ft_stack_size(*b);
	while (size)
	{
		pa(tmp, b, flag);
		c++;
		size--;
	}
	free_stack(b);
	return (c);
}

int					is_special(t_stack **a)
{
	if ((*a)->data == 4 && (*a)->next->data == 2 &&
		(*a)->next->next->data == 3 && (*a)->next->next->next->data == 1 &&
		(*a)->next->next->next->next->data == 5)
		return (1);
	if ((*a)->data == 4 && (*a)->next->data == 2 &&
		(*a)->next->next->data == 1 && (*a)->next->next->next->data == 3 &&
		(*a)->next->next->next->next->data == 5)
		return (2);
	return (0);
}

int					solve_insertion_sort(t_stack **a, char flag)
{
	int				size;
	int				min;
	t_stack			*b;
	int				c;

	b = 0;
	c = 0;
	size = ft_stack_size(*a);
	if (size == 5 && (is_special(a) == 1))
		return (solve5(a, &b, flag));
	if (size == 5 && (is_special(a) == 2))
		return (solve5_2(a, &b, flag));
	while (size > 3 && ++c)
	{
		min = find_min(*a);
		c += (min < (size / 2)) ? ra_loop(a, min, flag) :
			rra_loop(a, size - min, flag);
		if (stack_ordered(a))
			break ;
		pb(a, &b, flag);
		size--;
	}
	c += solve_easy_1(a, flag) + clean_b(a, &b, flag);
	return (c);
}
