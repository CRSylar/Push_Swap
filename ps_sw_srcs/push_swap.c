/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:28:55 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/22 15:33:00 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_best_solution(t_stack **a)
{
	t_stack *cpy;
	char	flag;
	int		size_ins;
	int		size_qk;

	flag = 0;
	flag |= BEST;
	if (stack_ordered(a))
		return ;
	cpy = t_copy_stack(a, 0);
	size_ins = solve_insertion_sort(&cpy, 0);
	free_stack(&cpy);
	cpy = t_copy_stack(a, 0);
	size_qk = solve_quick_sort(&cpy);
	free_stack(&cpy);
	cpy = t_copy_stack(a, flag);
	if (size_ins < size_qk)
		solve_insertion_sort(&cpy, BEST);
	else
		solve_quick_sort(&cpy);
	free_stack(&cpy);
}

int		check_input(char **av, t_stack **a)
{
	int			i;
	int			out;

	i = 1;
	while (av[i])
	{
		if (is_string(av[i]))
			string_handle(av[i], a);
		else
		{
			out = ft_atoi(av[i]);
			if (errno == 1)
			{
				write(2, "Error - invalid parameter\n", 26);
				exit(1);
			}
			ft_push_stack(a, out, 0);
		}
		i++;
	}
	if (ft_check_duplicates(a))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_stack *a;

	a = 0;
	if (ac < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!(check_input(av, &a)))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	find_best_solution(&a);
	free_stack(&a);
	return (0);
}
