/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:36:36 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/19 17:51:01 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		free_stack(t_stack **a)
{
	t_stack *freed;

	while (*a)
	{
		freed = (*a)->next;
		free(*a);
		(*a) = freed;
	}
	free(*a);
}

void		find_max(int *i, int *tmp, int size)
{
	int j;

	j = 0;
	*i = tmp[j];
	while (j < size)
	{
		if ((*i) < tmp[j])
			*i = tmp[j];
		j++;
	}
}

int		find_max_pos(int arr[], int size)
{
	int	ret;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	ret = -2147483648;
	while (i < size)
	{
		if (arr[i] > ret)
		{
			ret = arr[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int		find_min_pos(t_stack **a)
{
	int min;
	int pos;
	t_stack *tmp;

	pos = 0;
	min = 2147483647;
	tmp = *a;
	while (tmp->index != 0)
	{
		pos++;
		tmp = tmp->next;
	}
	return(pos);
}
