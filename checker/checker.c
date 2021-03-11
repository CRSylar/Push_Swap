/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:42:54 by cromalde          #+#    #+#             */
/*   Updated: 2021/03/11 20:18:46 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void    check_sol()
{
    
}

void    read_inst()
{
    char    *line;
    t_list *instr;

    line = 0;
    while (get_next_line(0, &line))
    {
        ft_ls
    }
}

int     check_input(char **av)
{
    int         i;
    int         out;
    t_stack     *a;

    i = 1;
    while (av[i])
    {
        out = ft_atoi(av[i]);
        if (errno == -1)
            return (0);
        ft_push_stack(&a, out);
        i++;
    }
}

int     main(int ac, char **av)
{
    if (ac > 1)
    {
        if (!check_input(av))
        {
            write(2, "Error\n", 6);
            return (1);
        }
        read_inst();
        check_sol();
    }
    return (0);
}