/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sw_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:49:11 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/21 14:18:41 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*ft_new_stack(int data, char flag)
{
	t_stack		*ret;

	ret = (t_stack*)malloc(sizeof(t_stack));
	ret->data = data;
	ret->flag = flag;
	ret->index = 0;
	ret->next = 0;
	return (ret);
}

t_stack		*t_copy_stack(t_stack **a, char flag)
{
	t_stack *ret;
	t_stack	*tmp;

	tmp = *a;
	ret = 0;
	while (tmp)
	{
		ft_push_stack(&ret, tmp->data, flag);
		tmp = tmp->next;
	}
	return (ret);
}

int			ft_check_duplicates(t_stack **a)
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
