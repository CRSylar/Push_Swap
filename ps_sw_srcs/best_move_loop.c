/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:10:59 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/23 15:33:54 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				insertion(t_stack **a, t_stack **b, int b_sz, int x)
{
	int	i;
	int	max;
	int	a_sz;
	int	*arr_a;
	int	*arr_b;

	i = 0;
	a_sz = ft_stack_size(*a);
	arr_a = copy_stack_index(*a, ft_stack_size(*a));
	arr_b = copy_stack_index(*b, b_sz);
	while (i < a_sz)
	{
		if (arr_b[x] < arr_a[i] && arr_b[x] > arr_a[(i == 0) ? 0 : i - 1])
			return (ft_free_arr(arr_a, arr_b) + i);
		if (arr_b[x] > arr_a[(a_sz - i) % a_sz] &&
			arr_b[x] < arr_a[((a_sz - i) + 1) % a_sz])
			return (-i + 1 + ft_free_arr(arr_a, arr_b));
		i++;
	}
	max = find_max_pos(arr_a, a_sz) + 1;
	max = (max == a_sz) ? 0 : max;
	max = (max > (a_sz - max)) ? -(a_sz - max) : max;
	ft_free_arr(arr_a, arr_b);
	return (max);
}

static void		new_best(int *op_a, int *op_b, int tmp, int i)
{
	*op_a = tmp;
	*op_b = i;
	return ;
}

int				find_best_insertion(t_stack **a, t_stack **b)
{
	int	tmp;
	int op_a;
	int	op_b;
	int	i;
	int	b_sz;

	i = 0;
	b_sz = ft_stack_size(*b);
	op_a = -ft_stack_size(*a);
	op_b = b_sz;
	while (i < b_sz)
	{
		if (count_ops(i, 0) >= count_ops(op_a, op_b))
			break ;
		tmp = insertion(a, b, b_sz, i);
		if (count_ops(tmp, i) < count_ops(op_a, op_b))
			new_best(&op_a, &op_b, tmp, i);
		tmp = insertion(a, b, b_sz, ((b_sz - i) % b_sz));
		if (count_ops(tmp, i) < count_ops(op_a, op_b))
			new_best(&op_a, &op_b, tmp, -i);
		i++;
	}
	return (do_rotation(a, b, op_a, op_b));
}
