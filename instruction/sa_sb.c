/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:06:30 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/19 17:18:41 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

void	sa(t_stack **a, char flag)
{
	int	tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	tmp = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = tmp;
	(flag & DEBUG) ? write(1, "-*- SA -*-\n", 11) : 0;
}

void	sb(t_stack **b, char flag)
{
	int	tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp;
	tmp = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = tmp;
	(flag & DEBUG) ? write(1, "-*- SB -*-\n", 11) : 0;
}

void	ss(t_stack **a, t_stack **b, char flag)
{
	(flag & DEBUG) ? write(1, "-*- SS -*-\n", 11) : 0;
	sa(a, 0);
	sb(b, 0);
}
