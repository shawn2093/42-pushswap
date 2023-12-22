/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:35:56 by long              #+#    #+#             */
/*   Updated: 2023/12/22 14:40:31 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int print)
{
	int	tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->number;
		(*a)->number = (*a)->next->number;
		(*a)->next->number = tmp;
	}
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	int	tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->number;
		(*b)->number = (*b)->next->number;
		(*b)->next->number = tmp;
	}
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	int	tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->number;
		(*a)->number = (*a)->next->number;
		(*a)->next->number = tmp;
	}
	if (*b && (*b)->next)
	{
		tmp = (*b)->number;
		(*b)->number = (*b)->next->number;
		(*b)->next->number = tmp;
	}
	if (print)
		write(1, "ss\n", 3);
}
