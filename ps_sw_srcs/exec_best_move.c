/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:12:42 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 12:37:40 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int		ra_rrb_sol(int best[], t_stack **a, t_stack **b)
{
	int ret;

	ret = 0;
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
	return (ret);
}

int		rra_rb_sol(int best[], t_stack **a, t_stack **b)
{
	int ret;

	ret = 0;
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
	return (ret);
}

int		diff_loop(t_stack **a, t_stack **b, int best[])
{
	int	ret;

	ret = 0;
	if (best[0] >= 0 && best[1] <= 0)
		ret = ra_rrb_sol(best, a, b);
	else if (best[0] <= 0 && best[1] >= 0)
		ret = rra_rb_sol(best, a, b);
	pa(a, b, (*a)->flag);
	ret++;
	return (ret);
}
