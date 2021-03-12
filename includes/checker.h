/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:36:16 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/12 12:16:51 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "instruction.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	print_stack(t_stack *a, int stack);
int		find_command(char *instr, t_stack **a, t_stack **b);
void	ft_push_stack(t_stack **a, int out);

#endif
