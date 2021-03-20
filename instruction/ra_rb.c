/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:31:37 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 09:57:36 by cromalde         ###   ########.fr       */
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
	*a = (*a)->next;
	tmp->next->next = 0;
	(flag & BEST) ? write(1, "ra\n", 3) : 0;
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
	*b = (*b)->next;
	tmp->next->next = 0;
	(flag & BEST) ? write(1, "rb\n", 3) : 0;
	(flag & DEBUG) ? write(1, "-*- RB -*-\n", 11) : 0;
}

void	rr(t_stack **a, t_stack **b, char flag)
{
	(flag & BEST) ? write(1, "rr\n", 3) : 0;
	(flag & DEBUG) ? write(1, "-*- RR -*-\n", 11) : 0;
	ra(a, 0);
	rb(b, 0);
}
