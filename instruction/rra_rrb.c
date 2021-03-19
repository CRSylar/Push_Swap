/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:35:58 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/19 19:12:17 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

void	rra(t_stack **a, char flag)
{
	t_stack *tmp;
	t_stack *ptr;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	ptr = tmp->next;
	tmp->next = 0;
	ptr->next = *a;
	*a = ptr;
	(flag & DEBUG) ? write(1, "-*- RRA -*-\n", 12) : 0;
}

void	rrb(t_stack **b, char flag)
{
	t_stack *tmp;
	t_stack *ptr;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	ptr = tmp->next;
	tmp->next = 0;
	ptr->next = *b;
	*b = ptr;
	(flag & DEBUG) ? write(1, "-*- RRB -*-\n", 12) : 0;
}

void	rrr(t_stack **a, t_stack **b, char flag)
{
	(flag & DEBUG) ? write(1, "-*- RRR -*-\n", 12) : 0;
	rra(a, 0);
	rrb(b, 0);
}
