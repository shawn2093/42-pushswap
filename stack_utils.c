/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:19:16 by long              #+#    #+#             */
/*   Updated: 2023/12/21 17:19:17 by long             ###   ########.fr       */
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
	ptr->target = -1;
	ptr->rank = -1;
	ptr->index = 0;
	ptr->cost = 0;
	return (ptr);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
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
		{
			*lst = new;
			new->prev = NULL;
		}
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

void	init_stack(char **av, t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (av[++i])
	{
		tmp = ft_stacknew((int)ft_atol(av[i]));
		if (!tmp)
			return ;
		ft_stackadd_back(a, tmp);
	}
}