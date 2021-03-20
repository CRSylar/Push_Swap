/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:15:22 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 15:27:19 by cromalde         ###   ########.fr       */
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
