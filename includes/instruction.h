/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:55:35 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/22 15:40:54 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include <unistd.h>
# include "../libft/libft.h"

# define DEBUG	0b00000001
# define COLOR	0b00000010
# define BEST	0b00000100

typedef struct		s_stack
{
	int				data;
	int				index;
	char			flag;
	struct s_stack	*next;
}					t_stack;

int					sa(t_stack **a, char flag);
int					sb(t_stack **b, char flag);
int					ss(t_stack **a, t_stack **b, char flag);
int					pa(t_stack **a, t_stack **b, char flag);
int					pb(t_stack **a, t_stack **b, char flag);
int					ra(t_stack **a, char flag);
int					rb(t_stack **b, char flag);
int					rr(t_stack **a, t_stack **b, char flag);
int					rra(t_stack **a, char flag);
int					rrb(t_stack **b, char flag);
int					rrr(t_stack **a, t_stack **b, char flag);
int					is_string(char *str);
void				string_handle(char *str, t_stack **a);

#endif
