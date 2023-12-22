/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:00:08 by long              #+#    #+#             */
/*   Updated: 2023/12/22 21:04:36 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *lst)
{
	t_stack	*min;
	t_stack	*max;
	t_stack	*last;

	min = min_finder(lst);
	max = max_finder(lst);
	last = ft_stacklast(lst);
	while (min != last)
	{
		if (min->next->number < min->number)
			return (0);
		min = min->next;
	}
	if (lst == min_finder(lst) && max == last)
		return (1);
	if ((last->number > lst->number) || max->next != min_finder(lst))
		return (0);
	while (lst != max)
	{
		if (lst->next->number < lst->number)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	invalid_error(char **new_av)
{
	int	i;
	int	j;

	i = 0;
	while (new_av[++i])
	{
		j = -1;
		while (new_av[i][++j])
		{
			if (new_av[i][j] == '-' || new_av[i][j] == '+')
			{
				if (j != 0 || new_av[i][j + 1] == 0)
					return (1);
			}
			else
			{
				if (!ft_isdigit(new_av[i][j]))
					return (1);
			}
		}
		if (!j || ft_atol(new_av[i]) < INT_MIN || ft_atol(new_av[i]) > INT_MAX)
			return (1);
	}
	return (0);
}

int	dup_error(char **new_av)
{
	int	i;
	int	j;

	i = 0;
	while (new_av[++i])
	{
		j = i;
		while (new_av[++j])
		{
			if (ft_atol(new_av[i]) == ft_atol(new_av[j]))
				return (1);
		}
	}
	return (0);
}

int	empty_error(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		if (av[i][0] == '\0')
			return (1);
		if (ac > 2)
		{	
			while (av[i][++j])
			{
				if ((av[i][j] == '-' || av[i][j] == '+')
					&& (j != 0 || av[i][j + 1] == 0))
					return (1);
				if (!(av[i][j] == '-' || av[i][j] == '+')
					&& !ft_isdigit(av[i][j]))
					return (1);
			}
		}
	}
	return (0);
}

char	**tidy_input(char **av)
{
	char	*str;
	char	*str1;
	char	*str2;
	int		i;
	char	**new_av;

	i = -1;
	str = ft_strdup("");
	while (av[++i])
	{
		str1 = ft_strjoin(str, av[i]);
		free(str);
		str2 = ft_strjoin(str1, " ");
		str = ft_strdup(str2);
		free(str1);
		free(str2);
	}
	new_av = ft_split(str, ' ');
	free(str);
	return (new_av);
}
