/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:46:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/21 15:05:39 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rot_array(int *a_cpy, int size)
{
	int	tmp;
	int	i;

	while (a_cpy[0] != 0)
	{
		i = 0;
		tmp = a_cpy[0];
		while (i < size - 1)
		{
			a_cpy[i] = a_cpy[i + 1];
			i++;
		}
		a_cpy[i] = tmp;
	}
}

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
	sort_array(sorted, size);
	create_index(sorted, a, size);
	a_cpy = copy_stack_index(*a, size);
	rot_array(a_cpy, size);
	free(sorted);
	return (build_seq(a, a_cpy, size));
}
