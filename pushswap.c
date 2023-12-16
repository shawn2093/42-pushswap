/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:32 by long              #+#    #+#             */
/*   Updated: 2023/12/16 17:11:47 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	minus_num;
	int	res;

	minus_num = 1;
	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_num *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * minus_num);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_stack	*ft_stacknew(int content)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return (0);
	ptr->number = content;
	ptr->next = NULL;
    ptr->prev = NULL;
    ptr->target = -1;
    ptr->index = 0;
    ptr->cost = 0;
	return (ptr);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (lst && new)
	{
		if (*lst)
		{
			tmp = ft_stacklast(*lst);
			tmp->next = new;
            new->prev = tmp;
		}
		else
			*lst = new;
	}
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
        (*lst)->prev = new;
		*lst = new;
	}
}

void init_stack(char **av, t_stack **a)
{
    int     i;
    t_stack *tmp;

    i = 0;
    tmp = (t_stack *) malloc(sizeof(t_stack));
    while(av[++i])
    {
        tmp = ft_stacknew(ft_atoi(av[i]));
        ft_stackadd_back(a, tmp);
    }
}

void pa(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    tmp = *b;
    *b = (*b)->next;
    if (*b)
        (*b)->prev = NULL;
    tmp->next = NULL;
    if (!*a)
        *a = tmp;
    else
        ft_stackadd_front(a, tmp);
    printf("pa\n");
}

void pb(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    tmp = *a;
    *a = (*a)->next;
    if (*a)
        (*a)->prev = NULL;
    tmp->next = NULL;
    if (!*b)
        *b = tmp;
    else
        ft_stackadd_front(b, tmp);
    printf("pb\n");
}

void ra(t_stack **a)
{
    t_stack *tmp;

    tmp = *a;
    *a = (*a)->next;
    tmp->next = NULL;
    (*a)->prev = NULL;
    ft_stackadd_back(a, tmp);
    write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
    t_stack *tmp;

    tmp = *b;
    *b = (*b)->next;
    tmp->next = NULL;
    (*b)->prev = NULL;
    ft_stackadd_back(b, tmp);
    write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    tmp = *a;
    *a = (*a)->next;
    tmp->next = NULL;
    (*a)->prev = NULL;
    ft_stackadd_back(a, tmp);
    tmp = *b;
    *b = (*b)->next;
    tmp->next = NULL;
    (*b)->prev = NULL;
    ft_stackadd_back(b, tmp);
    write(1, "rr\n", 3);
}

void rra(t_stack **a)
{
    t_stack *tmp;

    tmp = ft_stacklast(*a);
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    ft_stackadd_front(a, tmp);
    write(1, "rra\n", 4);
}

void rrb(t_stack **b)
{
    t_stack *tmp;

    tmp = ft_stacklast(*b);
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    ft_stackadd_front(b, tmp);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    t_stack *tmp;

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

void sa(t_stack **a)
{
    int     tmp;

    tmp = (*a)->number;
    (*a)->number = (*a)->next->number;
    (*a)->next->number = tmp;
    write(1, "sa\n", 3);
}

void sb(t_stack **b)
{
    int     tmp;

    tmp = (*b)->number;
    (*b)->number = (*b)->next->number;
    (*b)->next->number = tmp;
    write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
    int     tmp;

    tmp = (*a)->number;
    (*a)->number = (*a)->next->number;
    (*a)->next->number = tmp;
    tmp = (*b)->number;
    (*b)->number = (*b)->next->number;
    (*b)->next->number = tmp;
    write(1, "ss\n", 3);
}

int set_index_stacksize(t_stack **a)
{
    int     i;
    t_stack *tmp;

    i = 0;
    tmp = *a;
    while (tmp)
    {
        tmp->index = i;
        tmp->target = -1;
        i++;
        tmp = tmp->next;
    }
    // tmp = ft_stacklast(*a);
    // mid = 0;
    // while (++mid < i / 2)
    // {
    //     tmp->index = -mid;
    //     tmp = tmp->prev;
    // }    
    return (i);
}

void sortthree(t_stack **a)
{
    int first;
    int second;
    int third;

    first = (*a)->number;
    second = (*a)->next->number;
    third = (*a)->next->next->number;
    if (first < third && second > third)
    {
        ra(a);
        sa(a);
        rra(a);
    }
    else if (first < third && first > second)
        sa(a);
    else if (first < second && first > third)
        rra(a);
    else if (first > third && second < third)
        ra(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
}

t_stack *min_finder(t_stack *lst)
{
    int min;
    t_stack *tmp;

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

t_stack *max_finder(t_stack *lst)
{
    int max;
    t_stack *tmp;

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

void sortall(t_stack **a, t_stack **b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    t_stack *move;
    t_stack *max;
    t_stack *min;
    int     min_cost;
    int     len_a;
    int     len_b;
    int     move_a;
    int     move_b;
    
    if (set_index_stacksize(a) == 3)
        sortthree(a);
    else if (set_index_stacksize(a) == 2)
    {
        if ((*a)->number > (*a)->next->number)
            ra(a);
    }
    else
    {
        while (set_index_stacksize(a) > 3 && set_index_stacksize(b) < 2)
            pb(a, b);
        while (set_index_stacksize(a))
        {
            len_a = set_index_stacksize(a);
            tmp_a = *a;
            while (tmp_a)
            {
                len_b = set_index_stacksize(b);
                tmp_b = *b;
                while (tmp_b)
                {
                    if (tmp_b->prev == NULL)
                    {
                        if (tmp_a->number > tmp_b->number && tmp_a->number < ft_stacklast(*b)->number)
                            tmp_a->target = tmp_b->index;
                    }
                    else 
                    {
                        if (tmp_a->number > tmp_b->number && tmp_a->number < tmp_b->prev->number)
                            tmp_a->target = tmp_b->index;
                    }
                    tmp_b = tmp_b->next;
                }
                if (tmp_a->target == -1)
                {
                    max = max_finder(*b);
                    min = min_finder(*b);
                    if (tmp_a->number > max->number || tmp_a->number < min->number)
                        tmp_a->target = max->index;
                }
                tmp_a = tmp_a->next;
            }
            tmp_a = *a;
            move_a = MIN(tmp_a->index, len_a - tmp_a->index);
            move_b = MIN(tmp_a->target, len_b - tmp_a->target);
            min_cost = MAX(move_a, move_b);
            if ((move_a > len_a / 2 && move_b < len_b / 2) || (move_a < len_a / 2 && move_b > len_b / 2))
                min_cost = move_a + move_b;
            move = tmp_a;
            while (tmp_a)
            {
                move_a = MIN(tmp_a->index, len_a - tmp_a->index);
                move_b = MIN(tmp_a->target, len_b - tmp_a->target);
                if (min_cost > MAX(move_a, move_b))
                {
                    min_cost = MAX(move_a, move_b);
                    move = tmp_a;
                }
                if ((move_a > len_a / 2 && move_b < len_b / 2) || (move_a < len_a / 2 && move_b > len_b / 2))
                if (min_cost > move_a + move_b)
                {
                    min_cost = move_a + move_b;
                    move = tmp_a;
                }
                tmp_a = tmp_a->next;
            }
            if (move->index > len_a / 2 && move->target <= len_b / 2)
            {
                while (move->index++ < len_a)
                    rra(a);
                while (move->target-- > 0)
                    rb(b);
            }
            else if (move->index <= len_a / 2 && move->target > len_b / 2)
            {
                while (move->index-- > 0)
                    ra(a);
                while (move->target++ < len_b)
                    rrb(b);
            }
            else if (move->index <= len_a / 2 && move->target <= len_b / 2)
            {
                while (move->index-- > 0 && move->target-- > 0)
                    rr(a, b);
                while (move->index-- > 0)
                    ra(a);
                while (move->target-- > 0)
                    rb(b);
            }
            else if (move->index > len_a / 2 && move->target > len_b / 2)
            {
                while (move->index++ < len_a && move->target++ < len_b)
                    rrr(a, b);
                while (move->index++ < len_a)
                    rra(a);
                while (move->target++ < len_b)
                    rrb(b);
            }
            pb(a, b);
        }
        set_index_stacksize(b);
        max = max_finder(*b);
        while (max->index > 0 && max->index <= len_b / 2)
        {
            rb(b);
            max->index--;
        }
        while (max->index > len_b / 2 && max->index <= len_b)
        {
            rrb(b);
            max->index++;
        }
        while (set_index_stacksize(b))
            pa(a, b);
    }
}

int main(int ac, char **av)
{
    int     i;
    int     j;
    t_stack **a;
    t_stack **b;

    i = 0;
    if (ac >= 2)
    {
        while (++i < ac)
        {
            j = -1;
            while(av[i][++j])
            {
                if (!ft_isdigit(av[i][j]))
                    return(write(1, "Error\n", 6));
            }
        }
        i = 0;
        while(av[++i])
        {
            j = i;
            while(av[++j])
            {
                if (ft_atoi(av[i]) == ft_atoi(av[j]))
                    return(write(1, "Error\n", 6));
            }
        }
        a = (t_stack **)malloc(sizeof(t_stack *));
        b = (t_stack **)malloc(sizeof(t_stack *));
        init_stack(av, a);
        if (ac != 2)
            sortall(a, b);
        while (*b)
        {
            printf("b: %d\n", (*b)->number);
            printf("b_index: %d\n", (*b)->index);
            printf("b_target: %d\n", (*b)->target);
            (*b) = (*b)->next;
        }
        while (*a)
        {
            printf("a: %d\n", (*a)->number);
            printf("a_index: %d\n", (*a)->index);
            printf("a_target: %d\n", (*a)->target);
            (*a) = (*a)->next;
        }
        free(a);
        free(b);
    }
    return (0);
}

// pb
// pb
// rb
// pb
// ra
// pb
// rb
// rb
// pb
// pb
// rb
// pb
// pb
// pb
// ra
// pb
// rb
// rb
// rb
// rb
// pb
// ra
// rb
// pb
// rb
// pb
// rb
// rb
// pb
// rb
// pb
// rb
// rb
// pb
// rb
// rb
// rb
// rb
// rb
// rb
// rb
// rb
// pb
// rb
// pb
// rb
// rb
// rb
// rb
// rb
// rb
// rb
// rb
// rb
// rb
// rb
// rb
// rb
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa

// pb
// pb
// rra
// rra
// rb
// pb
// rra
// pb
// rra
// pb
// rra
// pb
// rra
// rra
// pb
// rra
// rra
// rb
// pb
// rrr
// rra
// rra
// pb
// rrr
// rrb
// rrb
// pb
// rra
// rb
// rb
// rb
// rb
// pb
// rrr
// pb
// rra
// rb
// rb
// rb
// pb
// rrr
// rrb
// rrb
// rrb
// pb
// rrr
// rrb
// rrb
// rrb
// pb
// ra
// ra
// rrb
// pb
// ra
// pb
// rb
// rb
// rb
// pb
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa


// pb
// pb
// rra
// rra
// rb
// pb
// rra
// pb
// rra
// pb
// rra
// pb
// rra
// rra
// pb
// rra
// rra
// rb
// pb
// rrr
// rra
// rra
// pb
// rrr
// rrb
// rrb
// pb
// rra
// rb
// rb
// rb
// rb
// pb
// rrr
// pb
// rra
// rb
// rb
// rb
// pb
// rrr
// rrb
// rrb
// rrb
// pb
// rrr
// rrb
// rrb
// rrb
// pb
// ra
// ra
// rrb
// pb
// ra
// pb
// rb
// rb
// rb
// pb
// rrb
// rrb
// rrb
// rrb
// rrb
// rrb
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa

// pb
// pb
// rra
// rb
// pb
// ra
// rrb
// pb
// rra
// rb
// rb
// pb
// rra
// rb
// pb
// rrb
// pb
// rra
// rb
// rb
// pb
// rb
// pb
// rrr
// pb
// pb
// rra
// rb
// pb
// rra
// rb
// pb
// rrr
// pb
// rra
// rb
// pb
// rb
// rb
// pb
// ra
// rrb
// rrb
// pb
// rb
// pb
// rrb
// rrb
// rrb
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa
// pa