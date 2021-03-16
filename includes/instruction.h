/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:55:35 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/16 17:48:55 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include <unistd.h>

# define DEBUG	0x00000001
# define COLOR	0x00000010

typedef struct		s_stack
{
	int				data;
	int				index;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
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

#endif
