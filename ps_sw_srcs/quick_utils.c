/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:57:09 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/16 10:55:12 by cromalde         ###   ########.fr       */
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

int		*copy_stack(t_stack *a, int size)
{
	t_stack *tmp;
	int		*ret;
	int		i;

	i = 0;
	tmp = a;
	ret = malloc(size * sizeof(int));
	while (tmp)
	{
		ret[i++] = tmp->data;
		tmp = tmp->next;
	}
	return (ret);
}

void	create_index(int *sorted, t_stack **a, int size)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->data == sorted[i])
			tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	find_max(int *i, int *tmp, int size)
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

void	sort_array(int *array, int size)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < (size - 1))
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}
