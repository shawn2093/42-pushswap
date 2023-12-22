/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 02:17:08 by long              #+#    #+#             */
/*   Updated: 2023/12/22 21:05:03 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse_cmd(t_list *tmp, t_stack **a, t_stack **b)
{
	if (ft_strcmp(tmp->str, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(tmp->str, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(tmp->str, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(tmp->str, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(tmp->str, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(tmp->str, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(tmp->str, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(tmp->str, "rrr\n") == 0)
		rrr(a, b, 0);
	else if (ft_strcmp(tmp->str, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(tmp->str, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(tmp->str, "ss\n") == 0)
		ss(a, b, 0);
}

int	create_oper_lst(t_list **cmd_lst, char **new_av, char *cmd)
{
	t_list	*tmp;

	while (cmd)
	{
		if (!check_cmd(cmd))
		{
			free_cmd(cmd_lst, new_av);
			return (1);
		}
		else
		{
			tmp = (t_list *)malloc(sizeof(t_list));
			if (!tmp)
			{
				free_cmd(cmd_lst, new_av);
				return (1);
			}
			tmp->str = cmd;
			tmp->next = NULL;
			ft_lstadd_back(cmd_lst, tmp);
		}
		cmd = get_next_line(0);
	}
	return (0);
}

void	exec_oper(char **new_av, t_list *cmd_lst)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*tmp;

	a = NULL;
	b = NULL;
	init_stack(new_av, &a);
	tmp = cmd_lst;
	while (tmp)
	{
		parse_cmd(tmp, &a, &b);
		tmp = tmp->next;
	}
	if (!b && a == min_finder(a) && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_cmd(&cmd_lst, new_av);
	free_stack(&a);
	if (b)
		free_stack(&b);
}

int	main(int ac, char **av)
{
	char	**new_av;
	char	*cmd;
	t_list	*cmd_lst;

	if (ac >= 2)
	{
		if (empty_error(ac, av))
			return (write(2, "Error\n", 6));
		new_av = tidy_input(av);
		if (invalid_error(new_av) || dup_error(new_av))
		{
			free_str(new_av);
			return (write(2, "Error\n", 6));
		}
		cmd_lst = NULL;
		cmd = get_next_line(0);
		if (create_oper_lst(&cmd_lst, new_av, cmd))
			return (write(2, "Error\n", 6));
		exec_oper(new_av, cmd_lst);
	}
	return (0);
}
