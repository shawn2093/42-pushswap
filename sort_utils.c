/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:01:40 by long              #+#    #+#             */
/*   Updated: 2023/12/22 00:23:49 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_index_size(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->index = i;
		tmp->target = -1;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*min_finder(t_stack *lst)
{
	int		min;
	t_stack	*tmp;

	min = lst->number;
	tmp = lst;
	while (lst)
	{
		if (lst->number < min)
		{
			min = lst->number;
			tmp = lst;
		}
		lst = lst->next;
	}
	return (tmp);
}

t_stack	*max_finder(t_stack *lst)
{
	int		max;
	t_stack	*tmp;

	max = lst->number;
	tmp = lst;
	while (lst)
	{
		if (lst->number > max)
		{
			max = lst->number;
			tmp = lst;
		}
		lst = lst->next;
	}
	return (tmp);
}

int	set_target_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		len_a;

	tmp_b = *b;
	while (tmp_b)
	{
		len_a = set_index_size(a);
		tmp_a = *a;
		while (tmp_a)
		{
			if (!tmp_a->prev && tmp_b->number < tmp_a->number
				&& tmp_b->number > ft_stacklast(*a)->number)
				tmp_b->target = tmp_a->index;
			if (tmp_a->prev && tmp_b->number < tmp_a->number
				&& tmp_b->number > tmp_a->prev->number)
				tmp_b->target = tmp_a->index;
			tmp_a = tmp_a->next;
		}
		if (tmp_b->target == -1 && (tmp_b->number > max_finder(*a)->number
				|| tmp_b->number < min_finder(*a)->number))
			tmp_b->target = min_finder(*a)->index;
		tmp_b = tmp_b->next;
	}
	return (len_a);
}

t_stack	*find_move(t_stack **b, int len_a, int len_b)
{
	t_stack	*tmp_b;
	t_stack	*move;
	int		move_a;
	int		move_b;

	tmp_b = *b;
	while (tmp_b)
	{
		move_a = MIN(tmp_b->target, len_a - tmp_b->target);
		move_b = MIN(tmp_b->index, len_b - tmp_b->index);
		tmp_b->cost = MAX(move_a, move_b);
		if ((move_a > len_a / 2 && move_b < len_b / 2) || (move_a < len_a / 2
				&& move_b > len_b / 2))
			tmp_b->cost = move_a + move_b;
		tmp_b = tmp_b->next;
	}
	tmp_b = *b;
	move = tmp_b;
	while (tmp_b->next)
	{
		if (tmp_b->next->cost < move->cost)
			move = tmp_b->next;
		tmp_b = tmp_b->next;
	}
	return (move);
}
