/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:03:29 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 11:44:16 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		r_loop(t_stack **a, t_stack **b, int best[])
{
	int ret;

	ret = 0;
	while (best[0] && best[1])
	{
		rr(a, b, (*a)->flag);
		best[0]--;
		best[1]--;
		ret++;
	}
	while (best[0])
	{
		ra(a, (*a)->flag);
		best[0]--;
		ret++;
	}
	while (best[1])
	{
		rb(b, (*a)->flag);
		best[1]--;
		ret++;
	}
	return (ret);
}

int		rr_loop(t_stack **a, t_stack **b, int best[])
{
	int ret;

	ret = 0;
	while (best[0] && best[1])
	{
		rrr(a, b, (*a)->flag);
		best[0]++;
		best[1]++;
		ret++;
	}
	while (best[0])
	{
		rra(a, (*a)->flag);
		best[0]++;
		ret++;
	}
	while (best[1])
	{
		rrb(b, (*a)->flag);
		best[1]++;
		ret++;
	}
	return (ret);
}

int		same_loop(t_stack **a, t_stack **b, int best[])
{
	int	ret;

	if (best[0] > 0)
		ret = (r_loop(a, b, best));
	else
		ret = (rr_loop(a, b, best));
	pa(a, b, (*a)->flag);
	ret++;
	return (ret);
}

int		diff_loop(t_stack **a, t_stack **b, int best[])
{
	int	ret;

	ret = 0;
	if (best[0] >= 0 && best[1] <= 0)
	{
		while (best[0])
		{
			ra(a, (*a)->flag);
			best[0]--;
			ret++;
		}
		while (best[1])
		{
			rrb(b, (*a)->flag);
			best[1]++;
			ret++;
		}
	}
	else if (best[0] <= 0 && best[1] >= 0)
	{
		while (best[0])
		{
			rra(a, (*a)->flag);
			best[0]++;
			ret++;
		}
		while (best[1])
		{
			rb(b, (*a)->flag);
			best[1]--;
			ret++;
		}
	}
	pa(a, b, (*a)->flag);
	ret++;
	return (ret);
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
