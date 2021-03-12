/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:35:58 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/12 10:42:32 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

void	rra(t_stack **a)
{
	t_stack *tmp;
	t_stack *ptr;

	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	ptr =  tmp->next;
	tmp->next = 0;
	ptr->next = *a;
	*a = ptr;
}

void	rrb(t_stack **b)
{
	t_stack *tmp;
	t_stack *ptr;

	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	ptr = tmp->next;
	tmp->next = 0;
	ptr->next = *b;
	*b = ptr;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}