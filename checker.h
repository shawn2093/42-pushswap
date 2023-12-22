/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:21:40 by long              #+#    #+#             */
/*   Updated: 2023/12/22 21:14:34 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include "push_swap.h"

int		ft_strcmp(char *s1, char *s2);
int		check_cmd(char *s1);
void	free_cmd(t_list **cmd_lst, char **new_av);
void	parse_cmd(t_list *tmp, t_stack **a, t_stack **b);
int		create_oper_lst(t_list **cmd_lst, char **new_av, char *cmd);
void	exec_oper(char **new_av, t_list *cmd_lst);

#endif
