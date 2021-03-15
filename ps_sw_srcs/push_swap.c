/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:28:55 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/15 18:02:23 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_best_solution(t_stack **a)
{
	t_stack *cpy;
	int		size_ins;
	int		size_qk;

/*
**	 prima controlla non sia gia in ordine **
*/
	if (stack_ordered(a))
		return ;
/*
**	runna gli algoritmi, poi vedi quello che ha usato meno istruzioni **
*/
	cpy = stack_copy(a);
	size_ins = solve_insertion_sort(&cpy);
	cpy = stack_copy(a);
	size_qk = solve_quick_sort(cpy);
}

int		check_input(char **av, t_stack **a)
{
	int			i;
	int			out;
	t_stack		*tmp;

	i = 1;
	while (av[i])
	{
		out = ft_atoi(av[i]);
		if (errno == 1)
			return (0);
		ft_push_stack(a, out);
		i++;
	}
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data == tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
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
	free_list(a);
	return (0);
}
