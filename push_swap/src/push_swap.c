/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:26:59 by mpelage           #+#    #+#             */
/*   Updated: 2024/12/29 19:39:55 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
    int i;
    t_list  *new_node;
    
    i = 0;
    if(argc < 2)
    {
        printf("Error\n arguments");
        return (0);
    }
    while(argv[i])
    {
        if(ft_atoi(argv[i]) >= -2147483648 && ft_atoi(argv[i]) <= 2147483647)
            ft 
    }
}