/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:57:09 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/21 14:28:11 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		*copy_stack_index(t_stack *a, int size)
{
	t_stack *tmp;
	int		*ret;
	int		i;

	i = 0;
	tmp = a;
	ret = malloc(size * sizeof(int));
	while (tmp)
	{
		ret[i++] = tmp->index;
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

int		ft_free_arr(int *a, int *b)
{
	free(a);
	free(b);
	return (0);
}
