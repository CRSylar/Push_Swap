/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:52:24 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/14 17:19:34 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quick_sort(t_stack *tmp, t_stack *b)
{

}

int		solve_quick_sort(t_stack **a)
{
	t_stack *tmp;
	t_stack *b;
	int		size;
	int		i;

	i = -1;
	tmp = *a;
	b = 0;
	size = stack_size(*a);
	while (++i < (size / 2))
		tmp = tmp->next;
	i = tmp->data;
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data < i)
		{
			pa(a, &b, 0);
			write(1, "pa\n", 3);
		}
		tmp = tmp->next;
	}
	quick_sort(tmp, b);
}
