/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:18:58 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/22 13:41:21 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	execute_flag(char flag, t_stack *a, t_stack *b)
{
	char	buff;

	if (flag & DEBUG)
	{
		ft_putstr_fd(GRN, -1, 1);
		print_stack(a, b);
		ft_putstr_fd(NC, -1, 1);
		ft_putstr_fd(YLL, -1, 1);
		ft_putendl_fd("\t-----------", 1);
		ft_putstr_fd(NC, -1, 1);
		while (1)
		{
			read(0, &buff, 1);
			if (buff == 'n')
				break ;
		}
	}
}

void	clr_wr(char *str, int status)
{
	if (status == 1)
	{
		ft_putstr_fd(GRN, -1, 1);
		ft_putstr_fd(str, -1, 1);
		ft_putendl_fd(NC, 1);
	}
	else if (!status)
	{
		ft_putstr_fd(RED, -1, 1);
		ft_putstr_fd(str, -1, 1);
		ft_putendl_fd(NC, 1);
	}
}
