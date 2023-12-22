/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:59:00 by long              #+#    #+#             */
/*   Updated: 2023/12/22 14:59:09 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_str(char **new_av)
{
	int		i;

	i = -1;
	while (new_av[++i])
		free(new_av[i]);
	free(new_av);
}

void	sortall(t_stack **a, t_stack **b)
{
	move_a_to_b(a, b);
	move_b_to_a(a, b);
	rot_min_to_top(a);
}
