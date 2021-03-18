/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:03:29 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/18 11:13:11 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		r_loop(t_stack **a, t_stack **b, int best[])
{
	int	ret;

	ret = 0;
	if ((best[0] * best[2]) > 0)
	{
		while (best[0] && best[2])
		{
			rr(a, b, 0);
			write(1, "rr\n", 3);
			best[0]--;
			best[2]--;
			ret++;
		}
		while (best[0])
		{
			ra(a, 0);
			write(1, "ra\n", 3);
			best[0]--;
			ret++;
		}
		while (best[2])
		{
			rb(b, 0);
			write(1, "rb\n", 3);
			best[2]--;
			ret++;
		}
	}
	else
	{
		while (best[0])
		{
			rra(a, 0);
			write(1, "rra\n", 4);
			(best[0] < 0) ? best[0]++ : best[0]--;
			ret++;
		}
		while (best[2])
		{
			rb(b, 0);
			write(1, "rb\n", 3);
			best[2]--;
			ret++;
		}
	}
	pa(a, b, 0);
	write(1, "pa\n", 3);
	ret++;
	return (ret);
}

int		rr_loop(t_stack **a, t_stack **b, int best[])
{
	int	ret;

	ret = 0;
	if ((best[0] * best[2]) > 0)
	{
		while (best[0] && best[2])
		{
			rrr(a, b, 0);
			write(1, "rrr\n", 4);
			best[0]++;
			best[2]++;
			ret++;
		}
		while (best[0])
		{
			rra(a, 0);
			write(1, "rra\n", 4);
			best[0]++;
			ret++;
		}
		while (best[2])
		{
			rrb(b, 0);
			write(1, "rrb\n", 4);
			best[2]++;
			ret++;
		}
	}
	else
	{
		while (best[0])
		{
			ra(a, 0);
			write(1, "ra\n", 3);
			best[0]--;
			ret++;
		}
		while (best[2])
		{
			rrb(b, 0);
			write(1, "rb\n", 3);
			best[2]++;
			ret++;
		}
	}
	pa(a, b, 0);
	write(1, "pa\n", 3);
	ret++;
	return (ret);
}

int		build_seq(t_stack *a, int *a_cpy, int size)
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

void	built_position(t_stack **a, t_stack **b)
{
	int			i;
	t_stack		*tmp;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
	tmp = *b;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}
