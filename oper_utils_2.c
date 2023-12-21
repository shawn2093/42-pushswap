/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:36:01 by long              #+#    #+#             */
/*   Updated: 2023/12/21 17:36:02 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;

	tmp = ft_stacklast(*a);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_stackadd_front(a, tmp);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	tmp = ft_stacklast(*b);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_stackadd_front(b, tmp);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = ft_stacklast(*a);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_stackadd_front(a, tmp);
	tmp = ft_stacklast(*b);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_stackadd_front(b, tmp);
	write(1, "rrr\n", 4);
}
