/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:32:27 by long              #+#    #+#             */
/*   Updated: 2023/12/22 14:39:16 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		tmp->next = NULL;
		if (!*a)
			*a = tmp;
		else
			ft_stackadd_front(a, tmp);
	}
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		tmp->next = NULL;
		if (!*b)
			*b = tmp;
		else
			ft_stackadd_front(b, tmp);
	}
	if (print)
		write(1, "pb\n", 3);
}

void	ra(t_stack **a, int print)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		(*a)->prev = NULL;
		ft_stackadd_back(a, tmp);
	}
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		(*b)->prev = NULL;
		ft_stackadd_back(b, tmp);
	}
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		(*a)->prev = NULL;
		ft_stackadd_back(a, tmp);
	}
	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		(*b)->prev = NULL;
		ft_stackadd_back(b, tmp);
	}
	if (print)
		write(1, "rr\n", 3);
}
