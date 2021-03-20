/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rr_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:03:29 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 12:14:39 by cromalde         ###   ########.fr       */
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
