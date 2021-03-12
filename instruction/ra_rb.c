/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:31:37 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/12 10:42:51 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

void	ra(t_stack **a)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	*a = (*a)->next;
	tmp->next->next = 0;
}

void	rb(t_stack **b)
{
	t_stack *tmp;

	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *b;
	*b = (*b)->next;
	tmp->next->next = 0;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}