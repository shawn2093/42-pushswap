/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:00:08 by long              #+#    #+#             */
/*   Updated: 2023/11/28 16:59:05 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_lstlast_gnl(t_gnl *lst)
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

void	ft_lstadd_back_gnl(t_gnl **lst, t_gnl *new)
{
	t_gnl	*tmp;

	if (lst && new)
	{
		if (*lst)
		{
			tmp = ft_lstlast_gnl(*lst);
			tmp->next = new;
		}
		else
			*lst = new;
	}
}

int	ft_lstsize_gnl(t_gnl *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	make_new(t_gnl **bufstr, char *str)
{
	t_gnl	*new;
	t_gnl	*tmp;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new)
		return ;
	new->str = str;
	new->next = NULL;
	while (*bufstr)
	{
		tmp = (*bufstr)->next;
		free((*bufstr)->str);
		free(*bufstr);
		*bufstr = tmp;
	}
	if (*str)
		*bufstr = new;
	else
	{
		free(str);
		free(new);
	}
}

void	clean_list(t_gnl **bufstr)
{
	int		i;
	int		k;
	t_gnl	*tmp;
	char	*str;

	if (!bufstr || !*bufstr)
		return ;
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return ;
	tmp = ft_lstlast_gnl(*bufstr);
	i = -1;
	k = 0;
	while (tmp->str[++i])
	{
		if (tmp->str[i] == '\n')
			break ;
	}
	while (tmp->str[i++])
		str[k++] = tmp->str[i];
	str[k] = 0;
	make_new(bufstr, str);
}
