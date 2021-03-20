/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sw_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:32:52 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 11:41:24 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_stack(t_stack **a, int out, char flag)
{
	t_stack *elem;
	t_stack *tmp;

	elem = ft_new_stack(out, flag);
	if (!(*a) || !a)
		*a = elem;
	else
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

int		ft_stack_size(t_stack *stack)
{
	int		i;
	t_stack *tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		stack_ordered(t_stack **a)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_list(t_stack *a)
{
	t_stack *tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}
