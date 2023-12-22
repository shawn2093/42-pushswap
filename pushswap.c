/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:32 by long              #+#    #+#             */
/*   Updated: 2023/12/22 14:58:34 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**new_av;
	t_stack	*a;
	t_stack	*b;

	if (ac >= 2)
	{
		if (empty_error(ac, av))
			return (write(2, "Error\n", 6));
		new_av = tidy_input(av);
		if (invalid_error(new_av) || dup_error(new_av))
		{
			free_str(new_av);
			return (write(2, "Error\n", 6));
		}
		a = NULL;
		b = NULL;
		init_stack(new_av, &a);
		sortall(&a, &b);
		free_str(new_av);
		free_stack(&a);
	}
	return (0);
}
