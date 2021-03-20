/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:46:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 12:14:42 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		align_stack_end(t_stack **a, int a_sz)
{
	int min;
	int ope;
	int i;

	ope = 0;
	i = 0;
	min = find_min_pos(a);
	if (min > a_sz / 2)
		while (i < (a_sz - min))
		{
			rra(a, (*a)->flag);
			ope++;
			i++;
		}
	else
		while (i < min)
		{
			ra(a, (*a)->flag);
			ope++;
			i++;
		}
	return (ope);
}

int		count_ops(int op_a, int op_b)
{
	if (op_a * op_b > 0)
		return (MAX(ABS(op_a), ABS(op_b)));
	else
		return (ABS(op_a) + ABS(op_b));
}

int		solve_quick_sort(t_stack **a)
{
	int		size;
	int		*sorted;
	int		*a_cpy;

	size = ft_stack_size(*a);
	sorted = copy_stack(*a, size);
	a_cpy = copy_stack(*a, size);
	sort_array(sorted, size);
	create_index(sorted, a, size);
	free(sorted);
	return (build_seq(a, a_cpy, size));
}
