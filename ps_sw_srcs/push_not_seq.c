/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_not_seq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:09:41 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/21 15:04:54 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	t_stack	*ft_stack_last(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int				init_solv(t_stack **a, int *seq, int seq_sz)
{
	t_stack	*b;
	int		count;
	int		ope;

	b = 0;
	ope = 0;
	count = seq_sz + 1;
	while (!is_in_sequence((ft_stack_last(*a))->index, seq, seq_sz))
		ope += rra(a, (*a)->flag) + pb(a, &b, (*a)->flag);
	while (*a && count)
	{
		if (!is_in_sequence((*a)->index, seq, seq_sz))
			ope += pb(a, &b, (*a)->flag);
		else
		{
			count--;
			ope += ra(a, (*a)->flag);
		}
	}
	free(seq);
	while (b)
		ope += find_best_insertion(a, &b);
	align_stack_end(a, ft_stack_size(*a));
	return (ope);
}
