/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:29:15 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/21 12:36:29 by cromalde         ###   ########.fr       */
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

t_stack		*t_copy_stack(t_stack **a, char flag);
int			ft_stack_size(t_stack *stack);
int			stack_ordered(t_stack **a);
int			ft_check_duplicates(t_stack **a);
void		ft_push_stack(t_stack **a, int out, char flag);
void		free_list(t_stack *a);

int			solve_insertion_sort(t_stack **a, char flag);
int			solve_quick_sort(t_stack **a);
/*
** Instertion utils **
*/
int			ra_loop(t_stack **tmp, int count, char flag);
int			rra_loop(t_stack **tmp, int	count, char flag);
int			solve_easy_1(t_stack **tmp, char flag);
int			solve_easy_2(t_stack **tmp, char flag);
int			solve5(t_stack **a, t_stack **b, char flag);
int			solve5_2(t_stack **a, t_stack **b, char flag);
int			find_min(t_stack *a);
/*
** Longest increasing sequece and Sort **
*/
t_stack		*ft_new_stack(int data, char flag);
void		create_index(int *sorted, t_stack **a, int size);
void		sort_array(int *array, int size);
int			*copy_stack(t_stack *a, int size);
int			*copy_stack_index(t_stack *a, int size);
int			build_seq(t_stack **a, int *a_cpy, int size);
int			find_seq_value(t_stack **a, int *a_cpy, int *tmp, int size);
int			is_in_sequence(int data, int *seq, int seq_sz);

void		find_max(int *i, int *tmp, int size);
int			find_max_pos(int arr[], int size);
int			find_min_pos(t_stack **a);

int			init_solv(t_stack **a, int *seq, int seq_sz);
int			find_best_insertion(t_stack **a, t_stack **b);
int			count_ops(int op_a, int op_b);
int			insertion(t_stack **a, t_stack **b, int b_sz, int x);
int			calc_rotation(t_stack **b, int best[]);
int			do_rotation(t_stack **a, t_stack **b, int op_a, int op_b);

int			same_loop(t_stack **a, t_stack **b, int best[]);
int			diff_loop(t_stack **a, t_stack **b, int best[]);

int			r_loop(t_stack **a, t_stack **b, int best[]);
int			rr_loop(t_stack **a, t_stack **b, int best[]);

int			align_stack_end(t_stack **a, int a_sz);

void		free_stack(t_stack **a);
int			ft_free_arr(int *a, int *b);

#endif
