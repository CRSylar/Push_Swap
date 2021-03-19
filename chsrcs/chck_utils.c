/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:15:22 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/19 17:20:03 by cromalde         ###   ########.fr       */
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

int		find_command(char *instr, t_stack **a, t_stack **b, char flag)
{
	if (!ft_memcmp(instr, "sa", ft_strlen(instr)))
		sa(a, flag);
	else if (!ft_memcmp(instr, "sb", ft_strlen(instr)))
		sb(b, flag);
	else if (!ft_memcmp(instr, "ss", ft_strlen(instr)))
		ss(a, b, flag);
	else if (!ft_memcmp(instr, "pa", ft_strlen(instr)))
		pa(a, b, flag);
	else if (!ft_memcmp(instr, "pb", ft_strlen(instr)))
		pb(a, b, flag);
	else if (!ft_memcmp(instr, "ra", ft_strlen(instr)))
		ra(a, flag);
	else if (!ft_memcmp(instr, "rb", ft_strlen(instr)))
		rb(b, flag);
	else if (!ft_memcmp(instr, "rr", ft_strlen(instr)))
		rr(a, b, flag);
	else if (!ft_memcmp(instr, "rra", ft_strlen(instr)))
		rra(a, flag);
	else if (!ft_memcmp(instr, "rrb", ft_strlen(instr)))
		rrb(b, flag);
	else if (!ft_memcmp(instr, "rrr", ft_strlen(instr)))
		rrr(a, b, flag);
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
		{
			ft_putstr_fd("A -> [", -1, 1);
			ft_putnbr_fd(tmp->data, 1);
			ft_putendl_fd("]", 1);
		}
		else
		{
			ft_putstr_fd("B -> [", -1, 1);
			ft_putnbr_fd(tmp->data, 1);
			ft_putendl_fd("]", 1);
		}
		tmp = tmp->next;
	}
}

int		check_duplicates(t_stack **a)
{
	t_stack *tmp;
	t_stack	*tmp2;

	tmp = *a;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp->next->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int		check_flag(char *flag, char **input)
{
	int		i;
	int		count;
	char	cpy_flag;

	i = 1;
	count = 0;
	cpy_flag = 0;
	while (input[i] && i < 3)
	{
		if ((!ft_memcmp(input[i], "-g", 3)) && ++count)
			cpy_flag |= DEBUG;
		if ((!ft_memcmp(input[i], "-c", 3)) && ++count)
			cpy_flag |= COLOR;
		if (!cpy_flag)
			return (0);
		i++;
	}
	*flag = cpy_flag;
	return (count);
}
