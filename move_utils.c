/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:26:59 by long              #+#    #+#             */
/*   Updated: 2023/12/21 17:27:00 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	move_a_to_b(t_stack **a, t_stack **b)
{
	if (set_index_size(a) == 3)
		sortthree(a);
	else if (set_index_size(a) == 2)
	{
		if ((*a)->number > (*a)->next->number)
			ra(a);
	}
	else
	{
		if (set_index_size(a) <= 100)
			insertsort(a, b, 1);
		else if (set_index_size(a) > 100 && set_index_size(a) < 500)
			insertsort(a, b, 2);
		else
			insertsort(a, b, 5);
	}
	if (set_index_size(a) == 3)
		sortthree(a);
}

void	rot_min_to_top(t_stack **a)
{
	t_stack	*min;
	int		len_a;

	len_a = set_index_size(a);
	min = min_finder(*a);
	while (min->index > 0 && min->index <= len_a / 2)
	{
		ra(a);
		min->index--;
	}
	while (min->index > len_a / 2 && min->index < len_a)
	{
		rra(a);
		min->index++;
	}
}
void	rot_rrb_dir(t_stack **a, t_stack **b, t_stack *move)
{
	int	len_a;
	int	len_b;

	len_b = set_index_size(b);
	len_a = set_target_b(a, b);
	if (move->index > len_b / 2 && move->target <= len_a / 2)
	{
		while (move->index++ < len_b)
			rrb(b);
		while (move->target-- > 0)
			ra(a);
	}
	else if (move->index > len_b / 2 && move->target > len_a / 2)
	{
		while (move->index < len_b && move->target < len_a)
		{
			rrr(a, b);
			move->index++;
			move->target++;
		}
		while (move->index++ < len_b)
			rrb(b);
		while (move->target++ < len_a)
			rra(a);
	}
}

void	rot_rb_dir(t_stack **a, t_stack **b, t_stack *move)
{
	int	len_a;
	int	len_b;

	len_b = set_index_size(b);
	len_a = set_target_b(a, b);
	if (move->index <= len_b / 2 && move->target > len_a / 2)
	{
		while (move->index-- > 0)
			rb(b);
		while (move->target++ < len_a)
			rra(a);
	}
	else if (move->index <= len_b / 2 && move->target <= len_a / 2)
	{
		while (move->index > 0 && move->target > 0)
		{
			rr(a, b);
			move->index--;
			move->target--;
		}
		while (move->index-- > 0)
			rb(b);
		while (move->target-- > 0)
			ra(a);
	}
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*move;
	int		len_a;
	int		len_b;

	while (set_index_size(b))
	{
		len_b = set_index_size(b);
		len_a = set_target_b(a, b);
		move = find_move(b, len_a, len_b);
		if ((move->index > len_b / 2 && move->target <= len_a / 2)
			|| (move->index > len_b / 2 && move->target > len_a / 2))
			rot_rrb_dir(a, b, move);
		else
			rot_rb_dir(a, b, move);
		pa(a, b);
	}
}