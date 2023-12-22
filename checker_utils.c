/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:20:43 by long              #+#    #+#             */
/*   Updated: 2023/12/22 21:13:18 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	count;

	count = 0;
	while (s1[count] != '\0' && s2[count] != '\0')
	{
		if (s1[count] == s2[count])
			count++;
		else
			return (s1[count] - s2[count]);
	}
	return (s1[count] - s2[count]);
}

int	check_cmd(char *s1)
{
	if (ft_strcmp(s1, "ra\n") != 0 && ft_strcmp(s1, "rb\n") != 0
		&& ft_strcmp(s1, "rr\n") != 0 && ft_strcmp(s1, "rra\n") != 0
		&& ft_strcmp(s1, "rrb\n") != 0 && ft_strcmp(s1, "rrr\n") != 0
		&& ft_strcmp(s1, "sa\n") != 0 && ft_strcmp(s1, "sb\n") != 0
		&& ft_strcmp(s1, "pa\n") != 0 && ft_strcmp(s1, "pb\n") != 0
		&& ft_strcmp(s1, "ss\n") != 0)
		return (0);
	return (1);
}

void	free_cmd(t_list **cmd_lst, char **new_av)
{
	t_list	*tmp;
	t_list	*current;

	if (!cmd_lst)
		return ;
	current = *cmd_lst;
	while (current)
	{
		tmp = current->next;
		if (current->str)
			free(current->str);
		free(current);
		current = tmp;
	}
	*cmd_lst = NULL;
	free_str(new_av);
}
