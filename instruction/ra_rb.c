/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:31:37 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/16 17:58:26 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

void	ra(t_stack **a, char flag)
{
	t_stack *tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	(*a)->prev = tmp;
	*a = (*a)->next;
	(*a)->prev = 0;
	tmp->next->next = 0;
	(flag & DEBUG) ? write(1, "-*- RA -*-\n", 11) : 0;
}

void	rb(t_stack **b, char flag)
{
	t_stack *tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *b;
	(*b)->prev = tmp;
	*b = (*b)->next;
	(*b)->prev = 0;
	tmp->next->next = 0;
	(flag & DEBUG) ? write(1, "-*- RB -*-\n", 11) : 0;
}

void	rr(t_stack **a, t_stack **b, char flag)
{
	(flag & DEBUG) ? write(1, "-*- RR -*-\n", 11) : 0;
	ra(a, 0);
	rb(b, 0);
}
