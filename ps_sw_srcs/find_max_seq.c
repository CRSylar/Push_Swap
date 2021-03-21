/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_seq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:06:28 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/21 14:54:36 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_seq_value(t_stack **a, int *a_cpy, int *tmp, int size)
{
	int		max_v;
	int		m_v_cpy;
	int		*seq_v;

	max_v = 0;
	find_max(&max_v, tmp, size);
	m_v_cpy = max_v;
	seq_v = malloc(sizeof(int) * (max_v));
	while (--size >= 0)
	{
		if (tmp[size] == max_v)
		{
			seq_v[max_v - 1] = a_cpy[size];
			max_v--;
		}
	}
	free(a_cpy);
	return (init_solv(a, seq_v, m_v_cpy));
}

int		build_seq(t_stack **a, int *a_cpy, int size)
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
	return (find_seq_value(a, a_cpy, tmp, size));
}
