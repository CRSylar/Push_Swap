/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:31:37 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/21 14:59:29 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

int		ra(t_stack **a, char flag)
{
	t_stack *tmp;

	if (!a || !*a || !(*a)->next)
	{
		(flag & DEBUG) ? ft_putendl_fd("\t-*- RA  -*-\n\t[A]\t[B]", 1) : 0;
		(flag & DEBUG) ?
		ft_putendl_fd("NO Operation done, A have 1 element\n", 1) : 0;
		return (0);
	}
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	*a = (*a)->next;
	tmp->next->next = 0;
	(flag & BEST) ? write(1, "ra\n", 3) : 0;
	(flag & DEBUG) ? ft_putendl_fd("\t-*- RA  -*-\n\t[A]\t[B]\n", 1) : 0;
	return (1);
}

int		rb(t_stack **b, char flag)
{
	t_stack *tmp;

	if (!b || !*b || !(*b)->next)
	{
		(flag & DEBUG) ? ft_putendl_fd("\t-*- RB  -*-\n\t[A]\t[B]", 1) : 0;
		(flag & DEBUG) ?
		ft_putendl_fd("NO Operation done, B have 1 element\n", 1) : 0;
		return (0);
	}
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *b;
	*b = (*b)->next;
	tmp->next->next = 0;
	(flag & BEST) ? write(1, "rb\n", 3) : 0;
	(flag & DEBUG) ? ft_putendl_fd("\t-*- RB  -*-\n\t[A]\t[B]\n", 1) : 0;
	return (1);
}

int		rr(t_stack **a, t_stack **b, char flag)
{
	(flag & BEST) ? write(1, "rr\n", 3) : 0;
	(flag & DEBUG) ? ft_putendl_fd("\t-*- RR  -*-\n\t[A]\t[B]\n", 1) : 0;
	return (ra(a, 0) + rb(b, 0));
}
