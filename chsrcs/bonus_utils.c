/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:18:58 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/14 12:21:02 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	execute_flag(char flag, t_stack *a, t_stack *b)
{
	char buff;

	if (flag & DEBUG)
	{
		(flag & COLOR) ? ft_putstr_fd(GRN, -1, 1) : 0;
		print_stack(a, 1);
		ft_putendl_fd("----------", 1);
		(flag & COLOR) ? ft_putstr_fd(NC, -1, 1) : 0;
		(flag & COLOR) ? ft_putstr_fd(YLL, -1, 1) : 0;
		print_stack(b, 2);
		ft_putendl_fd("__________", 1);
		(flag & COLOR) ? ft_putstr_fd(NC, -1, 1) : 0;
		while (read(0, &buff, 1))
			;
	}
}

void	clr_wr(char *str, int status)
{
	if (status == 1)
	{
		ft_putstr_fd(BLINK, -1, 1);
		ft_putstr_fd(GRN, -1, 1);
		ft_putendl_fd(str, 1);
		ft_putstr_fd(NC, -1, 1);
	}
	else if (!status)
	{
		ft_putstr_fd(BLINK, -1, 1);
		ft_putstr_fd(RED, -1, 1);
		ft_putendl_fd(str, 1);
		ft_putstr_fd(NC, -1, 1);
	}
}
