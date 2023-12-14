/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:32 by long              #+#    #+#             */
/*   Updated: 2023/12/14 22:12:33 by long             ###   ########.fr       */
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
    ptr->target = NULL;
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

int main(int ac, char **av)
{
    int     i;
    int     j;
    t_stack **a;
    t_stack **b;

    i = 0;
    if (ac >= 2)
    {
        a = (t_stack **)malloc(sizeof(t_stack *));
        b = (t_stack **)malloc(sizeof(t_stack *));
        while (++i < ac)
        {
            j = -1;
            while(av[i][++j])
            {
                if (!ft_isdigit(av[i][j]))
                    return(write(1, "Error\n", 6));
            }
        }
        init_stack(av, a);
        sortthree(a);
        while (*b)
        {
            printf("b: %d\n", (*b)->number);
            (*b) = (*b)->next;
        }
        while (*a)
        {
            printf("a: %d\n", (*a)->number);
            (*a) = (*a)->next;
        }
        free(a);
        free(b);
    }
    return (0);
}