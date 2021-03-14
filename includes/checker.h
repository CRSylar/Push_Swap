/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:36:16 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/14 12:11:51 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "instruction.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define DEBUG	0x00000001
# define COLOR	0x00000010
# define YLL	"\x1b[33m"
# define GRN	"\x1b[32m"
# define RED	"\x1b[31m"
# define NC		"\033[0m"
# define BLINK	"\x1b[5m"

void	print_stack(t_stack *a, int stack);
int		find_command(char *instr, t_stack **a, t_stack **b, char flag);
void	ft_push_stack(t_stack **a, int out);
int		check_duplicates(t_stack **a);
int		check_flag(char *flag, char **input);

void	execute_flag(char flag, t_stack *a, t_stack *b);
void	clr_wr(char *str, int status);

#endif
