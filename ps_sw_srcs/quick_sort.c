/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:46:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/15 15:35:30 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int		solve_quick_sort(t_stack *a)
{
	int		i;
	int		size;
	int		*sorted;
	t_stack	*tmp;

	tmp = a;
	i = 0;
	size = ft_stack_size(a);
	sorted = malloc(size * sizeof(int));
	while (tmp)
	{
		sorted[i++] = tmp->data;
		tmp = tmp->next;
	}
	sort_array(sorted, size);
	create_index(sorted, &a, size);
	/* while (a)
	{
		printf("(%d)--[%d]\n", a->data, a->index);
		a = a->next;
	} */
	return (1);
}
