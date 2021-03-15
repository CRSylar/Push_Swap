/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:57:09 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/15 15:09:36 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*stack_copy(t_stack **a)
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
