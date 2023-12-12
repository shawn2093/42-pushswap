/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:32 by long              #+#    #+#             */
/*   Updated: 2023/12/12 23:34:53 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
    printf("ra\n");
}

void rra(t_stack **a)
{
    t_stack *tmp;

    tmp = ft_stacklast(*a);
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    ft_stackadd_front(a, tmp);
    printf("rra\n");
}

void sa(t_stack **a)
{
    int     tmp;

    tmp = (*a)->number;
    (*a)->number = (*a)->next->number;
    (*a)->next->number = tmp;
    printf("sa\n");
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

void sortall()sds

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
                    return(ft_printf("Error\n"));
            }
        }
        init_stack(av, a);
        sortthree(a);
        while (*b)
        {
            ft_printf("b: %d\n", (*b)->number);
            (*b) = (*b)->next;
        }
        while (*a)
        {
            ft_printf("a: %d\n", (*a)->number);
            (*a) = (*a)->next;
        }
        free(a);
        free(b);
    }
    return (0);
}