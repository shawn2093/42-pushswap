/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:32 by long              #+#    #+#             */
/*   Updated: 2023/12/21 18:01:13 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*a = NULL;
}

void	sortall(t_stack **a, t_stack **b)
{
	move_a_to_b(a, b);
	move_b_to_a(a, b);
	rot_min_to_top(a);
}

int	main(int ac, char **av)
{
	int		i;
	char	**new_av;
	t_stack	*a;
	t_stack	*b;

	i = -1;
	if (ac >= 2)
	{
		if (ac == 2 && av[1][0] == '\0')
			return (write(2, "Error\n", 6));
		new_av = tidy_input(av);
		if (invalid_error(new_av) || dup_error(new_av))
			return (write(2, "Error\n", 6));
		a = NULL;
		b = NULL;
		init_stack(new_av, &a);
		sortall(&a, &b);
		i = -1;
		while (new_av[++i])
			free(new_av[i]);
		free(new_av);
		free_stack(&a);
	}
	return (0);
}
