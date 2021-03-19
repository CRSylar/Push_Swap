/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sw_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:32:52 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/19 11:13:52 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*t_copy_stack(t_stack **a)
{
	t_stack *ret;
	t_stack	*tmp;

	tmp = *a;
	ret = 0;
	while (tmp)
	{
		ft_push_stack(&ret, tmp->data);
		tmp = tmp->next;
	}
	return (ret);
}

int		ft_check_duplicates(t_stack **a)
{
	t_stack *tmp;
	t_stack	*tmp2;

	tmp = *a;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_push_stack(t_stack **a, int out)
{
	t_stack *new;
	t_stack *tmp;
	int		i;

	i = 0;
	new = malloc(sizeof(t_stack));
	new->data = out;
	new->next = 0;
	new->prev = 0;
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
	new->prev = tmp;
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
			printf(GRN"A ->[%d]-idx-[%d]-pos-[%d]"NC"\n",
			tmp->data, tmp->index, tmp->pos);
		else
			printf(YLL"B ->[%d]-idx-[%d]-pos-[%d]"NC"\n",
			tmp->data, tmp->index, tmp->pos);
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
