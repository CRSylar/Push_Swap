/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:42:54 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/12 11:43:27 by cromalde         ###   ########.fr       */
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

void	check_sol(t_list *instr, t_stack **a)
{
	t_stack *b;
	t_stack *tmp;

	b = 0;
	while (instr)
	{
		if (find_command(instr->content, a, &b) == -1)
		{
			write(2, "Error\n", 6);
			return ;
		}
		/* print_stack(*a, 1);
		printf("---------\n");
		print_stack(b, 2);
		printf("___________\n"); */
		instr = instr->next;
	}
	tmp = *a;
	while (tmp->next)
	{
		if (!(tmp->data < tmp->next->data))
		{
			write(1, "KO\n", 3);
			return ;
		}
		tmp = tmp->next;
	}
	write(1, "OK\n", 3);
	return ;
}

int		read_inst(t_stack *a)
{
	int		ret;
	char	*line;
	t_list	*instr;

	line = 0;
	instr = 0;
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			return (ret);
		ft_lstadd_back(&instr, ft_lstnew(line));
		//ft_lstadd_front(&instr, ft_lstnew(line));
	}
	check_sol(instr, &a);
	return (0);
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
		if (errno == -1)
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
	t_stack	*a;
	
	a = 0;
	if (ac > 1)
	{
		if (!check_input(av, &a))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (read_inst(a) == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}