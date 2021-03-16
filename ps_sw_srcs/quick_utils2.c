/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:03:29 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/16 18:05:54 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	build_seq(t_stack *a, int *a_cpy, int size)
{
	int		tmp[size];
	int		i;
	int		j;

	j = 0;
	while (j < size)
		tmp[j++] = 1;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < j)
		{
			if (a_cpy[i] < a_cpy[j] && tmp[i] == tmp[j])
				tmp[j]++;
			i++;
		}
		j++;
	}
	find_seq_value(a, a_cpy, tmp, size);
}

int		is_in_sequence(int data, int *seq, int seq_sz)
{
	int i;

	i = 0;
	while (i < seq_sz)
	{
		if (data == seq[i])
			return (1);
		i++;
	}
	return (0);
}

void	built_position(t_stack **b)
{
	int			i = 0;
	t_stack		*tmp;

	tmp = *b;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}

/* int		is_best(t_stack *a, t_stack *b, int *idx, int i)
{

} */

int		*parse_b(t_stack **a, t_stack **b, int i)
{
	char		flag;
	int			*idx;
	t_stack		*tmp_b;
	t_stack		*tmp_a;

	flag = 0;
	tmp_b = *b;
	idx = malloc(2 * sizeof(int));
	idx[0] = tmp_b->index;
	while (tmp_b)
	{
		tmp_a = *a;
		while (tmp_a)
		{
			if (ABS((tmp_a->index - tmp_b->index)) == i)
			{
				idx[0] = tmp_b->index;
				idx[1] = tmp_b->pos;
				/* if (flag = is_best(tmp_a, tmp_b, idx, i))
					break; */
			}
			tmp_a = tmp_a->next;
		}
		/* if (flag)
			break; */
		tmp_b = tmp_b->next;
	}
	return (idx);
}
