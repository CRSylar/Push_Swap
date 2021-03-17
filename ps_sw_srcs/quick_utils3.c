/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:36:36 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/17 15:52:20 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		calc_rotation(t_stack **b, int best[])
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *b;
	while (tmp->index != best[2])
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
