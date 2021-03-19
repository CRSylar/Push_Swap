/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:25:21 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/19 17:16:27 by cromalde         ###   ########.fr       */
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
	(flag & DEBUG) ? write(1, "-*- PB -*-\n", 11) : 0;
}
