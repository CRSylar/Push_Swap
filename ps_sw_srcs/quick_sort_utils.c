/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:58:09 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/14 15:59:46 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		stack_size(t_stack *stack)
{
	t_stack *tmp;
	int		i;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	i++;
}
