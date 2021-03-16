/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:46:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/16 13:01:54 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_best_insertion(t_stack **tmp, t_stack **b)
{
	print_stack(*tmp, 1);
	print_stack(*b, 2);
}

void	init_solv(t_stack *a, int *seq, int seq_sz)
{
	t_stack	*tmp;
	t_stack	*b;
	int		count;

	b = 0;
	tmp = a;
	count = seq_sz;
	while (tmp && count)
	{
		if (!is_in_sequence(tmp->data, seq, seq_sz))
		{
			pb(&tmp, &b, 0);
			write(1, "pb\n", 3);
		}
		else
		{
			count--;
			ra(&tmp, 0);
			write(1, "ra\n", 3);
		}
	}
	find_best_insertion(&tmp, &b);
}

void	find_seq_value(t_stack *a, int *a_cpy, int *tmp, int size)
{
	int		max_v;
	int		m_v_cpy;
	int		*seq_v;

	max_v = 0;
	find_max(&max_v, tmp, size);
	m_v_cpy = max_v;
	seq_v = malloc(sizeof(int) * max_v);
	while (size > 0)
	{
		if (tmp[size] == max_v)
		{
			seq_v[max_v - 1] = a_cpy[size];
			max_v--;
		}
		size--;
	}
	init_solv(a, seq_v, m_v_cpy);
}

int		solve_quick_sort(t_stack *a)
{
	int		size;
	int		*sorted;
	int		*a_cpy;

	size = ft_stack_size(a);
	sorted = copy_stack(a, size);
	a_cpy = copy_stack(a, size);
	sort_array(sorted, size);
	create_index(sorted, &a, size);
	free(sorted);
	build_seq(a, a_cpy, size);
	return (1);
}
