/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:46:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 11:27:54 by cromalde         ###   ########.fr       */
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

int		do_rotation(t_stack **a, t_stack **b, int op_a, int op_b)
{
	int ope;
	int best[2];

	best[0] = op_a;
	best[1] = op_b;
	if ((op_a * op_b) > 0)
		ope = same_loop(a, b, best);
	else
		ope = diff_loop(a, b, best);
	return (ope);
}

int		count_ops(int op_a, int op_b)
{
	if (op_a * op_b > 0)
		return (MAX(ABS(op_a), ABS(op_b)));
	else
		return (ABS(op_a) + ABS(op_b));
}

int		insertion(t_stack **a, t_stack **b, int b_sz, int x)
{
	int	i;
	int	max;
	int	a_sz;
	int	*arr_a;
	int	*arr_b;

	i = 0;
	a_sz = ft_stack_size(*a);
	arr_a = copy_stack_index(*a, ft_stack_size(*a));
	arr_b = copy_stack_index(*b, b_sz);
	while (i < a_sz)
	{
		if (arr_b[x] < arr_a[i] && arr_b[x] > arr_a[(i == 0) ? 0 : i - 1])
		{
			free(arr_a);
			free(arr_b);
			return (i);
		}
		if (arr_b[x] > arr_a[(a_sz - i) % a_sz] &&
			arr_b[x] < arr_a[((a_sz - i) + 1) % a_sz])
		{
			free(arr_a);
			free(arr_b);
			return (-i + 1);
		}
		i++;
	}
	max = find_max_pos(arr_a, a_sz) + 1;
	if (max == a_sz)
		max = 0;
	if (max > (a_sz - max))
		max = -(a_sz - max);
	free(arr_a);
	free(arr_b);
	return (max);
}

int		find_best_insertion(t_stack **a, t_stack **b)
{
	int	tmp;
	int	tmp2;
	int op_a;
	int	op_b;
	int	i;
	int	b_sz;

	i = 0;
	b_sz = ft_stack_size(*b);
	op_a = -ft_stack_size(*a);
	op_b = b_sz;
	while (i < b_sz)
	{
		if (count_ops(i, 0) >= count_ops(op_a, op_b))
			break ;
		tmp = insertion(a, b, b_sz, i);
		if (count_ops(tmp, i) < count_ops(op_a, op_b))
		{
			op_a = tmp;
			op_b = i;
		}
		tmp2 = insertion(a, b, b_sz, ((b_sz - i) % b_sz));
		if (count_ops(tmp2, i) < count_ops(op_a, op_b))
		{
			op_a = tmp2;
			op_b = -i;
		}
		i++;
	}
	return (do_rotation(a, b, op_a, op_b));
}

int		init_solv(t_stack **a, int *seq, int seq_sz)
{
	t_stack	*b;
	int		count;
	int		ope;

	b = 0;
	ope = 0;
	count = seq_sz + 1;
	while (*a && count)
	{
		if (!is_in_sequence((*a)->data, seq, seq_sz) && ++ope)
			pb(a, &b, (*a)->flag);
		else
		{
			ope++;
			count--;
			ra(a, (*a)->flag);
		}
	}
	free(seq);
	while (b)
		ope += find_best_insertion(a, &b);
	align_stack_end(a, ft_stack_size(*a));
	return (ope);
}

int		find_seq_value(t_stack **a, int *a_cpy, int *tmp, int size)
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
	free(a_cpy);
	return (init_solv(a, seq_v, m_v_cpy));
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
