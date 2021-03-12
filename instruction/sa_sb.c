/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:06:30 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/12 11:34:52 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

void	sa(t_stack **a)
{
	int	tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp; 
}

void	sb(t_stack **b)
{
	int	tmp;
	
	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}