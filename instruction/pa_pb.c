/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:25:21 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/21 14:58:22 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

int		pa(t_stack **a, t_stack **b, char flag)
{
	t_stack *tmp;

	if (!*b)
	{
		(flag & DEBUG) ? ft_putendl_fd("\t-*- PA  -*-\n\t[A]\t[B]", 1) : 0;
		(flag & DEBUG) ? ft_putendl_fd("NO Operation done, B is EMPTY\n", 1) :
		0;
		return (0);
	}
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	(flag & BEST) ? write(1, "pa\n", 3) : 0;
	(flag & DEBUG) ? ft_putendl_fd("\t-*- PA  -*-\n\t[A]\t[B]\n", 1) : 0;
	return (1);
}

int		pb(t_stack **a, t_stack **b, char flag)
{
	t_stack *tmp;

	if (!*a)
	{
		(flag & DEBUG) ? ft_putendl_fd("\t-*- PA  -*-\n\t[A]\t[B]", 1) : 0;
		(flag & DEBUG) ? ft_putendl_fd("NO Operation done, B is EMPTY\n", 1) :
		0;
		return (0);
	}
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	(flag & BEST) ? write(1, "pb\n", 3) : 0;
	(flag & DEBUG) ? ft_putendl_fd("\t-*- PB  -*-\n\t[A]\t[B]\n", 1) : 0;
	return (1);
}
