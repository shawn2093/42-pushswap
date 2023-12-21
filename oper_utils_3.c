/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:35:56 by long              #+#    #+#             */
/*   Updated: 2023/12/21 17:35:57 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sa(t_stack **a)
{
	int	tmp;

	tmp = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int	tmp;

	tmp = (*b)->number;
	(*b)->number = (*b)->next->number;
	(*b)->next->number = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	int	tmp;

	tmp = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = tmp;
	tmp = (*b)->number;
	(*b)->number = (*b)->next->number;
	(*b)->next->number = tmp;
	write(1, "ss\n", 3);
}