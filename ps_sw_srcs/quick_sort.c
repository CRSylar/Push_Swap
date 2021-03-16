/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:46:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/16 18:19:18 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		rotate_stacks(t_stack **a, t_stack **b, int *mv_idx, int i)
{
	int	a_sz;
	int	b_sz;
	int count = 0;
i++;
	a_sz = ft_stack_size(*a);
	b_sz = ft_stack_size(*b);
	while ((*b)->pos != mv_idx[1])
	{
		if (mv_idx[1] > (b_sz / 2))
		{
			rrb(b, 0);
			write(1, "rrb\n", 4);
		}
		else
		{
			rb(b, 0);
			write(1, "rb\n", 3);
		}
		count++;
	}
	/* while (((*a)->index != mv_idx[0] - 1) && ((*a)->index != mv_idx[0] + 1))
	{
		if ((*a)->index > (a_sz / 2))
			rra(a, 0);
		else
			ra(a, 0);
		count++;
	} */
	pa(a, b, 0);
	write(1, "pa\n", 3);
	return (count + 1);
}

void	find_best_insertion(t_stack **tmp, t_stack **b)
{
	int		b_sz;
	int		a_sz;
	int		*mv_idx;
	int		i;
	int		ope;

	i = 1;
	ope = 0;
	a_sz = ft_stack_size(*tmp);
	b_sz = ft_stack_size(*b);
	while (b_sz > 4)
	{
		b_sz = ft_stack_size(*b);
		built_position(b);
		built_position(tmp);
		while (1)
		{
			mv_idx = parse_b(tmp, b, i);
			if ((mv_idx[1] > (b_sz - 3)) || (mv_idx[1] < (b_sz + 3)))
			{
				ope += rotate_stacks(tmp, b, mv_idx, i);
				break;
			}
			else
				i++;
		}
	}
	//printf("ope[%d]\n", ope);
	printf("{%d}-[%d]\n", mv_idx[0], mv_idx[1]);
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
