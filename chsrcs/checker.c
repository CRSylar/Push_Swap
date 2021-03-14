/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:42:54 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/14 18:02:09 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	check_sol(t_list *instr, t_stack **a, char flag)
{
	static t_stack	*b;
	t_stack			*tmp;

	while (instr)
	{
		if (find_command(instr->content, a, &b, flag) == -1)
		{
			write(2, "Error\n", 6);
			return ;
		}
		(flag) ? execute_flag(flag, *a, b) : 0;
		instr = instr->next;
	}
	tmp = *a;
	while (tmp->next)
	{
		if (!(tmp->data < tmp->next->data) && !b)
		{
			(flag & COLOR) ? clr_wr("KO", 0) : write(1, "KO\n", 3);
			return ;
		}
		tmp = tmp->next;
	}
	(flag & COLOR) ? clr_wr("OK", 1) : write(1, "OK\n", 3);
	return ;
}

int		read_inst(t_stack *a, char flag)
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
	check_sol(instr, &a, flag);
	return (0);
}

int		check_input(char **av, t_stack **a, char *flag)
{
	int			i;
	int			out;

	i = 1;
	i += check_flag(flag, av);
	while (av[i])
	{
		out = ft_atoi(av[i]);
		if (errno == 1)
			return (0);
		ft_push_stack(a, out);
		i++;
	}
	if (check_duplicates(a))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_stack		*a;
	static char	flag;

	a = 0;
	if (ac > 1)
	{
		if (!check_input(av, &a, &flag))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (read_inst(a, flag) == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}
