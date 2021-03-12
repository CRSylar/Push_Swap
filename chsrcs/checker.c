/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:42:54 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/12 17:26:16 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
		print_stack(*a, 1);
		printf("-----------\n");
		print_stack(b, 2);
		printf("___________\n");
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