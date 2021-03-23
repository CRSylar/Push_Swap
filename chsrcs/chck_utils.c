/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:15:22 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/23 10:19:46 by cromalde         ###   ########.fr       */
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
	if (!ft_memcmp(instr, "sa", MAX(ft_strlen(instr), 3)))
		sa(a, flag);
	else if (!ft_memcmp(instr, "sb", MAX(ft_strlen(instr), 3)))
		sb(b, flag);
	else if (!ft_memcmp(instr, "ss", MAX(ft_strlen(instr), 3)))
		ss(a, b, flag);
	else if (!ft_memcmp(instr, "pa", MAX(ft_strlen(instr), 3)))
		pa(a, b, flag);
	else if (!ft_memcmp(instr, "pb", MAX(ft_strlen(instr), 3)))
		pb(a, b, flag);
	else if (!ft_memcmp(instr, "ra", MAX(ft_strlen(instr), 3)))
		ra(a, flag);
	else if (!ft_memcmp(instr, "rb", MAX(ft_strlen(instr), 3)))
		rb(b, flag);
	else if (!ft_memcmp(instr, "rr", MAX(ft_strlen(instr), 3)))
		rr(a, b, flag);
	else if (!ft_memcmp(instr, "rra", MAX(ft_strlen(instr), 4)))
		rra(a, flag);
	else if (!ft_memcmp(instr, "rrb", MAX(ft_strlen(instr), 4)))
		rrb(b, flag);
	else if (!ft_memcmp(instr, "rrr", MAX(ft_strlen(instr), 4)))
		rrr(a, b, flag);
	else
		return (-1);
	return (0);
}

void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	char	flag;

	tmp = a;
	tmp2 = b;
	flag = 0;
	while (tmp || tmp2)
	{
		ft_putstr_fd(GRN, -1, 1);
		ft_putstr_fd("\t", -1, 1);
		(tmp) ? ft_putnbr_fd(tmp->data, 1) : 0;
		(!flag) ? ft_putstr_fd(YLL, -1, 1) : ft_putstr_fd(RED, -1, 1);
		flag++;
		ft_putstr_fd("\t", -1, 1);
		(tmp2) ? ft_putnbr_fd(tmp2->data, 1) : 0;
		ft_putendl_fd(NC, 1);
		(tmp) ? tmp = tmp->next : 0;
		(tmp2) ? tmp2 = tmp2->next : 0;
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
		if (!cpy_flag)
			return (0);
		i++;
	}
	*flag = cpy_flag;
	return (count);
}
