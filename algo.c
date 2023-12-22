/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:41:20 by long              #+#    #+#             */
/*   Updated: 2023/12/22 14:43:56 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortthree(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->number;
	second = (*a)->next->number;
	third = (*a)->next->next->number;
	if (first < third && second > third)
	{
		ra(a, 1);
		sa(a, 1);
		rra(a, 1);
	}
	else if (first < third && first > second)
		sa(a, 1);
	else if (first < second && first > third)
		rra(a, 1);
	else if (first > third && second < third)
		ra(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
}

int	*sort_rank(int *array, t_stack *a, int j)
{
	int	i;
	int	k;
	int	tmp;

	i = -1;
	while (++i < j)
	{
		array[i] = a->number;
		a = a->next;
	}
	i = -1;
	while (++i < j)
	{
		k = i;
		while (++k < j)
		{
			if (array[i] > array[k])
			{
				tmp = array[i];
				array[i] = array[k];
				array[k] = tmp;
			}
		}
	}
	return (array);
}

void	set_rank(t_stack **a, int div, int j)
{
	int		*array;
	int		i;
	int		group;
	t_stack	*tmp_a;

	tmp_a = *a;
	array = (int *)malloc(sizeof(int) * j);
	if (!array)
		return ;
	group = j / div;
	if (group * div != set_index_size(a))
		group++;
	array = sort_rank(array, *a, j);
	while (tmp_a)
	{
		i = -1;
		while (++i < j)
		{
			if (tmp_a->number == array[i])
				break ;
		}
		tmp_a->rank = i / group;
		tmp_a = tmp_a->next;
	}
	free(array);
}

void	div_n_conq(t_stack **a, t_stack **b, t_stack *tmp_a, int i)
{
	t_stack	*move;
	int		len_a;

	len_a = set_index_size(a);
	move = tmp_a;
	while (tmp_a)
	{
		if (tmp_a->rank == i && tmp_a->cost < move->cost)
			move = tmp_a;
		tmp_a = tmp_a->next;
	}
	if (move->index <= len_a / 2)
	{
		while (move->index-- > 0)
			ra(a, 1);
	}
	else
	{
		while (move->index++ < len_a)
			rra(a, 1);
	}
	pb(a, b, 1);
}

void	insertsort(t_stack **a, t_stack **b, int div)
{
	int		i;
	int		len_a;
	t_stack	*tmp_a;

	set_rank(a, div, set_index_size(a));
	i = 0;
	while (set_index_size(a) > 3 && !is_sorted(*a))
	{
		len_a = set_index_size(a);
		tmp_a = *a;
		while (tmp_a)
		{
			tmp_a->cost = MIN(tmp_a->index, len_a - tmp_a->index);
			tmp_a = tmp_a->next;
		}
		tmp_a = *a;
		while (tmp_a->rank != i && tmp_a->next)
			tmp_a = tmp_a->next;
		if (tmp_a->rank != i)
			tmp_a = NULL;
		if (!tmp_a)
			i++;
		else
			div_n_conq(a, b, tmp_a, i);
	}
}
