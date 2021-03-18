/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:46:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/18 12:55:10 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_limit(int index_limit[], t_stack *a)
{
	index_limit[0] = 1000000;
	index_limit[1] = -1000000;
	while (a)
	{
		if (a->index < index_limit[0])
			index_limit[0] = a->index;
		if (a->index > index_limit[1])
			index_limit[1] = a->index;
		a = a->next;
	}
	printf("limits [%d]/[%d]\n", index_limit[0], index_limit[1]);
	sleep(2);
}

int		calc_best(int top[], int bottom[])
{
	int top_diff;
	int	btt_diff;

	top_diff = top[0] - top[2];
	btt_diff = bottom[0] - bottom[2];

	if (ABS(top_diff) < ABS(btt_diff))
		return (1);
	return (-1);
}

int		do_best_insertion(t_stack **a, t_stack **b, int top[], int bottom[])
{
	int ope;
	int	best;

	ope = 0;
	best = calc_best(top, bottom);
	if (best > 0)
		ope += r_loop(a, b, top);
	else
		ope += rr_loop(a, b, bottom);
	return (ope);
}

int		find_best_insertion(t_stack **a, t_stack **b)
{
	t_stack	*a_end;
	t_stack	*b_tmp;
	t_stack	*a_tmp;
	t_stack	*a_vend;
	int		i;
	int		index_limit[2];
	int		best_top[4];
	int		best_down[4];

	built_position(a, b);
	find_limit(index_limit, *a);
	best_top[0] = 0;
	best_down[0] = 0;
	a_vend = *a;
	b_tmp = *b;
	a_tmp = *a;
	while (a_vend->next)
		a_vend = a_vend->next;
	while (b_tmp)
	{
		i = 0;
		a_tmp = *a;
		a_end = a_vend;
		best_top[3] = 0;
		while ((b_tmp->index > index_limit[0]) && (b_tmp->index < index_limit[1]))
		{
			if (b_tmp->index < a_end->index)
				a_end = a_end->prev;
			if (b_tmp->index > a_tmp->index)
				a_tmp = a_tmp->next;
			i++;
		}
		if (!i && ((best_top[0] = 0)))
			break ;
		if (!(b_tmp->index > a_tmp->index))
			best_top[0] = a_tmp->pos;
		else if (!(b_tmp->index < a_end->index))
		{
			best_top[0] = a_tmp->next->pos;
			best_top[3] = 1;
		}
		b_tmp = b_tmp->next;
		if (b_tmp && (b_tmp->pos >= best_top[0]))
		{
			best_top[1] = b_tmp->prev->index;
			best_top[2] = b_tmp->prev->pos;
			break ;
		}
	}
	b_tmp = *b;
	while (b_tmp->next)
		b_tmp = b_tmp->next;
	while (b_tmp)
	{
		i = 0;
		a_tmp = *a;
		a_end = a_vend;
		best_down[3] = 0;
		while ((b_tmp->index > index_limit[0]) && (b_tmp->index < index_limit[1]))
		{
			if (b_tmp->index < a_end->index)
				a_end = a_end->prev;
			if (b_tmp->index > a_tmp->index)
				a_tmp = a_tmp->next;
			i++;
		}
		if (!i && ((best_down[0] = 0)))
			break ;
		if (!(b_tmp->index > a_tmp->index))
			best_down[0] = a_tmp->pos;
		else if (!(b_tmp->index < a_end->index))
		{
			best_down[0] = a_tmp->next->pos;
			best_down[3] = 1;
		}
		b_tmp = b_tmp->prev;
		if (b_tmp && ((ft_stack_size(*b) - b_tmp->pos) >= best_down[0]))
		{
			best_down[1] = b_tmp->next->index;
			best_down[2] = b_tmp->next->pos - ft_stack_size(*b);
			break ;
		}
	}
	(best_top[3]) ? best_top[0] = -best_top[0] + 1 : 0;
	(best_down[3]) ? best_down[0] = -best_down[0] + 1 : 0;
/* 	printf("best_top[%d] - best_down{%d}\n", best_top[0], best_down[0]);
	printf("best_top-idx[%d] - best_down-idx{%d}\n", best_top[1], best_down[1]);
	printf("best_top-b-pos[%d] - best_down-b-pos{%d}\n", best_top[2], best_down[2]); */
	return (do_best_insertion(a, b, best_top, best_down));
}

int		init_solv(t_stack *a, int *seq, int seq_sz)
{
	t_stack	*tmp;
	t_stack	*b;
	int		count;
	int		ope;

	b = 0;
	ope = 0;
	tmp = a;
	count = seq_sz;
	while (tmp && count)
	{
		if (!is_in_sequence(tmp->data, seq, seq_sz) && ++ope)
		{
			pb(&tmp, &b, 0);
			write(1, "pb\n", 3);
		}
		else
		{
			ope++;
			count--;
			ra(&tmp, 0);
			write(1, "ra\n", 3);
		}
	}
	while (b)
		ope += find_best_insertion(&tmp, &b);
//	print_stack(a, 1);
	return (ope);
}

int		find_seq_value(t_stack *a, int *a_cpy, int *tmp, int size)
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
	return (init_solv(a, seq_v, m_v_cpy));
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
	return (build_seq(a, a_cpy, size));
}
