/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:06:30 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/11 19:43:35 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

void	sa(t_stack **a)
{
	t_stack *tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp->data; 
}

void	sb(t_stack **b)
{
	t_stack *tmp;
	
	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp->data;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}