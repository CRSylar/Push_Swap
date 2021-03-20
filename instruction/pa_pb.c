/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:25:21 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 09:55:59 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

void	pa(t_stack **a, t_stack **b, char flag)
{
	t_stack *tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	(flag & BEST) ? write(1, "pa\n", 3) : 0;
	(flag & DEBUG) ? write(1, "-*- PA -*-\n", 11) : 0;
}

void	pb(t_stack **a, t_stack **b, char flag)
{
	t_stack *tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	(flag & BEST) ? write(1, "pb\n", 3) : 0;
	(flag & DEBUG) ? write(1, "-*- PB -*-\n", 11) : 0;
}
