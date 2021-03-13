/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:29:15 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/13 12:41:37 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "instruction.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_push_stack(t_stack **a, int out);
int		solve_insertion_sort(t_stack **a);
int		ft_stack_size(t_stack *stack);
int		stack_ordered(t_stack **a);
void	print_stack(t_stack *a, int stack);
void	free_list(t_stack *a);

#endif
