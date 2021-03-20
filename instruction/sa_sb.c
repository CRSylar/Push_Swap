/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:06:30 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 16:30:32 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

void	sa(t_stack **a, char flag)
{
	int	tmp;

	if (!*a || !(*a)->next)
	{
		(flag & DEBUG) ? ft_putendl_fd("\t-*- SA  -*-\n\t[A]\t[B]", 1) : 0;
		(flag & DEBUG) ?
		ft_putendl_fd("NO Operation done, A have 1 element\n", 1) : 0;
		return ;
	}
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	tmp = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = tmp;
	(flag & BEST) ? write(1, "sa\n", 3) : 0;
	(flag & DEBUG) ? ft_putendl_fd("\t-*- SA  -*-\n\t[A]\t[B]\n", 1) : 0;
}

void	sb(t_stack **b, char flag)
{
	int	tmp;

	if (!*b || !(*b)->next)
	{
		(flag & DEBUG) ? ft_putendl_fd("\t-*- SB  -*-\n\t[A]\t[B]", 1) : 0;
		(flag & DEBUG) ?
		ft_putendl_fd("NO Operation done, B have 1 element \n", 1) : 0;
		return ;
	}
	tmp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp;
	tmp = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = tmp;
	(flag & BEST) ? write(1, "sb\n", 3) : 0;
	(flag & DEBUG) ? ft_putendl_fd("\t-*- SB  -*-\n\t[A]\t[B]\n", 1) : 0;
}

void	ss(t_stack **a, t_stack **b, char flag)
{
	(flag & BEST) ? write(1, "ss\n", 3) : 0;
	(flag & DEBUG) ? ft_putendl_fd("\t-*- SS  -*-\n\t[A]\t[B]\n", 1) : 0;
	sa(a, 0);
	sb(b, 0);
}
