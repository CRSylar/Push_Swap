/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:46:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/17 13:40:33 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_best_insertion(t_stack **a, t_stack **b)
{
	t_stack	*b_end;
	t_stack	*b_tmp;
	t_stack *a_tmp;
	int		a_sz;
	int		i;
	int		count;
	int		best_top[3];
	int		best_bottom[3];

	i = 0;
	count = 0;
	b_end = *b;
	b_tmp = *b;
	a_tmp = *a;
	a_sz = (ft_stack_size(a_tmp) - count);
	while (b_end->next)
		b_end = b_end->next;
	best_top[0] = ABS((a_tmp->index - b_tmp->index));
	best_bottom[0] = ABS((a_tmp->index - b_end->index));
	best_bottom[1] = a_sz;
	best_top[1] = a_sz;
	//printf("top[%d] - bottom[%d]\n", best_top, best_bottom);
	while (i < 4)
	{
		a_tmp = *a;
		count = 0;
		while (a_tmp)
		{
			if ((ABS((a_tmp->index - b_tmp->index)) < best_top[0])
				&& count < best_top[1])
			{
				best_top[0] = ABS((a_tmp->index - b_tmp->index));
				best_top[1] = count;
				best_top[2] = b_tmp->index;
			}
			if ((ABS((a_tmp->index - b_end->index)) <= best_bottom[0])
				&& (a_sz - count)  < best_bottom[1])
			{
				best_bottom[0] = ABS((a_tmp->index - b_end->index));
				best_bottom[1] = a_sz - count;
				best_bottom[2] = b_end->index;
			}
			a_tmp = a_tmp->next;
			count++;
		}
		b_tmp = b_tmp->next;
		b_end = b_end->prev;
		i++;
	}
	printf("B-> [%d]", best_bottom[2]);
	printf("top[%d]/[%d] - bottom[%d]/[%d]\n", best_top[0], best_top[1], best_bottom[0], best_bottom[1]);
	return (1);
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
	print_stack(tmp, 1);
	print_stack(b, 2);
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
