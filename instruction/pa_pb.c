/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:25:21 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/17 16:07:35 by cromalde         ###   ########.fr       */
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
	(*b) ? (*b)->prev = 0 : 0;
	tmp->next = *a;
	(*a) ? (*a)->prev = tmp : 0;
	*a = tmp;
	(flag & DEBUG) ? write(1, "-*- PA -*-\n", 11) : 0;
}

void	pb(t_stack **a, t_stack **b, char flag)
{
	t_stack *tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a) ? (*a)->prev = 0 : 0;
	tmp->next = *b;
	(*b) ? (*b)->prev = tmp : 0;
	*b = tmp;
	(flag & DEBUG) ? write(1, "-*- PB -*-\n", 11) : 0;
}
