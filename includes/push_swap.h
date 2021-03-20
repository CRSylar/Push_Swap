/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:29:15 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/20 10:53:07 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "instruction.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX(x,y) ((x > y) ? x : y)
# define ABS(x) ((x > 0) ? x : -x)

# define DEBUG	0b00000001
# define COLOR	0b00000010
# define BEST	0b00000100

# define YLL	"\x1b[33m"
# define GRN	"\x1b[32m"
# define RED	"\x1b[31m"
# define NC		"\033[0m"
# define BLINK	"\x1b[5m"

void		ft_push_stack(t_stack **a, int out);
int			ft_stack_size(t_stack *stack);
int			stack_ordered(t_stack **a);
void		print_stack(t_stack *a, int stack);
void		free_list(t_stack *a);
t_stack		*t_copy_stack(t_stack **a);

int			solve_insertion_sort(t_stack **a, char flag);
int			solve_quick_sort(t_stack **a, int flag);
/*
** Instertion utils **
*/
int			ra_loop(t_stack **tmp, int count,char flag);
int			rra_loop(t_stack **tmp, int	count, char flag);
int			find_min(t_stack *a);
int			ft_check_duplicates(t_stack **a);
/*
** Quick Sort **
*/

t_stack		*ft_new_stack(int data);
int			*copy_stack(t_stack *a, int size);
int			*copy_stack_index(t_stack *a, int size);
int			is_in_sequence(int data, int *seq, int seq_sz);
int			build_seq(t_stack **a, int *a_cpy, int size);
void		create_index(int *sorted, t_stack **a, int size);
void		sort_array(int *array, int size);
int			find_seq_value(t_stack **a, int *a_cpy, int *tmp, int size);

int			r_loop(t_stack **a, t_stack **b, int best[]);
int			rr_loop(t_stack **a, t_stack **b, int best[]);

int			calc_rotation(t_stack **b, int best[]);
void		find_max(int *i, int *tmp, int size);
int			find_max_pos(int arr[], int size);
int			find_min_pos(t_stack **a);

int			same_loop(t_stack **a, t_stack **b, int best[]);
int			diff_loop(t_stack **a, t_stack **b, int best[]);

void		free_stack(t_stack **a);

#endif
