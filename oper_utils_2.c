/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:36:01 by long              #+#    #+#             */
/*   Updated: 2023/12/22 14:39:55 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int print)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = ft_stacklast(*a);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		ft_stackadd_front(a, tmp);
	}
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (*b && (*b)->next)
	{
		tmp = ft_stacklast(*b);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		ft_stackadd_front(b, tmp);
	}
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = ft_stacklast(*a);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		ft_stackadd_front(a, tmp);
	}
	if (*b && (*b)->next)
	{
		tmp = ft_stacklast(*b);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		ft_stackadd_front(b, tmp);
	}
	if (print)
		write(1, "rrr\n", 4);
}
