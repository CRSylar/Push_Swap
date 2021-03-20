/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:55:35 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 10:52:31 by cromalde         ###   ########.fr       */
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
	struct s_stack	*next;
}					t_stack;

void				sa(t_stack **a, char flag);
void				sb(t_stack **b, char flag);
void				ss(t_stack **a, t_stack **b, char flag);
void				pa(t_stack **a, t_stack **b, char flag);
void				pb(t_stack **a, t_stack **b, char flag);
void				ra(t_stack **a, char flag);
void				rb(t_stack **b, char flag);
void				rr(t_stack **a, t_stack **b, char flag);
void				rra(t_stack **a, char flag);
void				rrb(t_stack **b, char flag);
void				rrr(t_stack **a, t_stack **b, char flag);
void				string_handle(char *str, t_stack **a);
int					is_string(char *str);

#endif
