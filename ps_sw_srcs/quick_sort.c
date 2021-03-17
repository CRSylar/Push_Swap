/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:46:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/17 18:45:31 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		do_best_insertion(t_stack **a, t_stack **b, int top[], int bottom[])
{
	int ope;

	ope = 0;
 	printf("top[%d]-[%d]-[%d]\n bottom[%d]-[%d]-[%d]", top[0], top[1], top[2], bottom[0], bottom[1], bottom[2]);
	print_stack(*a, 1);
	print_stack(*b, 2);
	if (top[1] < bottom[1])
		ope += r_loop(a, b, top);
	else
		ope += rr_loop(a, b, bottom);
	/* if ((*a)->index > (*a)->next->index)
	{	sa(a, 0);
		write(1, "sa\n", 3);} */
	sleep(5);
	return (ope);
}

int		find_best_insertion(t_stack **a, t_stack **b)
{
	t_stack	*a_end;
	t_stack	*b_tmp;
	t_stack *a_tmp;
	int		a_sz;
	int		i;
	int		count;
	int		best[3];

	i = 0;
	built_position(a, b);
	count = 0;
	a_end = *a;
	b_tmp = *b;
	a_tmp = *a;
	a_sz = ft_stack_size(a_tmp);
	while (a_end->next)
		a_end = a_end->next;
		while ((b_tmp->index > a_tmp->index) && (b_tmp->index < a_end->index))
		{
		if (b_tmp->index < a_end->index)
			a_end = a_end->prev;
		if (b_tmp->index > a_tmp->index)
			a_tmp = a_tmp->next;
	}
	if (!(b_tmp->index > a_tmp->index))
		count = a_tmp->prev->pos;
	else if (!(b_tmp->index < a_end->index))
		count = a_tmp->next->pos;
	if (count > (a_sz / 2))
		count = a_sz - count;
	while (b_tmp)
	{

		/* a_tmp = *a;
		count = 0;
		while (a_tmp)
		{
			if ((ABS((a_tmp->index - b_tmp->index)) < best_top[0])
				&& count > best_top[1])
			{
				best_top[0] = ABS((a_tmp->index - b_tmp->index));
				best_top[1] = a_sz - count;
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
		i++; */
	}
	//return (do_best_insertion(a, b, best));
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
