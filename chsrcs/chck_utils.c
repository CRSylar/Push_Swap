/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:15:22 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/12 12:16:06 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_push_stack(t_stack **a, int out)
{
	t_stack *new;
	t_stack *tmp;

	new = malloc(sizeof(t_stack));
	new->data = out;
	new->next = 0;
	if (!*a)
	{
		*a = new;
		return ;
	}
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int		find_command(char *instr, t_stack **a, t_stack **b)
{
	if (!ft_memcmp(instr, "sa", ft_strlen(instr)))
		sa(a);
	else if (!ft_memcmp(instr, "sb", ft_strlen(instr)))
		sb(b);
	else if (!ft_memcmp(instr, "ss", ft_strlen(instr)))
		ss(a, b);
	else if (!ft_memcmp(instr, "pa", ft_strlen(instr)))
		pa(a, b);
	else if (!ft_memcmp(instr, "pb", ft_strlen(instr)))
		pb(a, b);
	else if (!ft_memcmp(instr, "ra", ft_strlen(instr)))
		ra(a);
	else if (!ft_memcmp(instr, "rb", ft_strlen(instr)))
		rb(b);
	else if (!ft_memcmp(instr, "rr", ft_strlen(instr)))
		rr(a, b);
	else if (!ft_memcmp(instr, "rra", ft_strlen(instr)))
		rra(a);
	else if (!ft_memcmp(instr, "rrb", ft_strlen(instr)))
		rrb(b);
	else if (!ft_memcmp(instr, "rrr", ft_strlen(instr)))
		rrr(a, b);
	else
		return (-1);
	return (0);
}

void	print_stack(t_stack *a, int stack)
{
	t_stack *tmp;

	tmp = a;
	while (tmp)
	{
		if (stack == 1)
			printf("A ->[%d]\n", tmp->data);
		else
			printf("B ->[%d]\n", tmp->data);
		tmp = tmp->next;
	}
}
