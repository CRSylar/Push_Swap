/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sw_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:32:52 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/16 12:05:04 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_stack(t_stack **a, int out)
{
	t_stack *new;
	t_stack *tmp;
	int		i;

	i = 0;
	new = malloc(sizeof(t_stack));
	new->data = out;
	new->next = 0;
	if (!*a)
	{
		*a = new;
		return ;
	}
	tmp = *a;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	tmp->next = new;
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

void	print_stack(t_stack *a, int stack)
{
	t_stack *tmp;

	tmp = a;
	while (tmp)
	{
		if (stack == 1)
			printf(GRN"A ->[%d]-idx-[%d]"NC"\n", tmp->data, tmp->index);
		else
			printf(YLL"B ->[%d]-idx-[%d]"NC"\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
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
