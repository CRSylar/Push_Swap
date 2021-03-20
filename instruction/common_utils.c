/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:48:20 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 09:44:25 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction.h"

static	void	ft_push_stack(t_stack **a, int out)
{
	t_stack *new;
	t_stack *tmp;
	int		i;

	i = 0;
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
	{
		i++;
		tmp = tmp->next;
	}
	tmp->next = new;
}

static void		free_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int				is_string(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			return (1);
		i++;
	}
	return (0);
}

void			string_handle(char *str, t_stack **a)
{
	char	**out;
	int		i;
	int		num;

	i = 0;
	out = ft_split(str, ' ');
	while (out[i])
	{
		num = ft_atoi(out[i]);
		if (errno == 1)
		{
			write(2, "Error - invalid parameter\n", 26);
			exit(1);
		}
		ft_push_stack(a, num);
		i++;
	}
	free_split(out);
}
