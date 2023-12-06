/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:32 by long              #+#    #+#             */
/*   Updated: 2023/12/04 16:30:48 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    if (ac >= 2)
    {
        while (++i < ac)
        {
            j = -1;
            while(av[i][++j])
            {
                if (!ft_isdigit(av[i][j]))
                    return(ft_printf("Error\n"));
            }
        }
    }
    return (0);
}