/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:35:58 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 16:29:48 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

void	rra(t_stack **a, char flag)
{
	t_stack *tmp;
	t_stack *ptr;

	if (!a || !*a || !(*a)->next)
	{
		(flag & DEBUG) ? ft_putendl_fd("\t-*- RRA -*-\n\t[A]\t[B]", 1) : 0;
		(flag & DEBUG) ?
		ft_putendl_fd("NO Operation done, A have 1 element\n", 1) : 0;
		return ;
	}
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	ptr = tmp->next;
	tmp->next = 0;
	ptr->next = *a;
	*a = ptr;
	(flag & BEST) ? write(1, "rra\n", 4) : 0;
	(flag & DEBUG) ? ft_putendl_fd("\t-*- RRA -*-\n\t[A]\t[B]\n", 1) : 0;
}

void	rrb(t_stack **b, char flag)
{
	t_stack *tmp;
	t_stack *ptr;

	if (!b || !*b || !(*b)->next)
	{
		(flag & DEBUG) ? ft_putendl_fd("\t-*- RRB -*-\n\t[A]\t[B]", 1) : 0;
		(flag & DEBUG) ?
		ft_putendl_fd("NO Operation done, B have 1 element\n", 1) : 0;
		return ;
	}
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	ptr = tmp->next;
	tmp->next = 0;
	ptr->next = *b;
	*b = ptr;
	(flag & BEST) ? write(1, "rrb\n", 4) : 0;
	(flag & DEBUG) ? ft_putendl_fd("\t-*- RRB -*-\n\t[A]\t[B]\n", 1) : 0;
}

void	rrr(t_stack **a, t_stack **b, char flag)
{
	(flag & BEST) ? write(1, "rrr\n", 4) : 0;
	(flag & DEBUG) ? ft_putendl_fd("\t-*- RRR -*-\n\t[A]\t[B]\n", 1) : 0;
	rra(a, 0);
	rrb(b, 0);
}
