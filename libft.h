/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:40:39 by long              #+#    #+#             */
/*   Updated: 2023/12/22 00:14:56 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define MIN(x, y) (x < y) ? x : y
# define MAX(x, y) (x < y) ? y : x

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	int				index;
	int				target;
	int				cost;
	int				rank;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int		ft_isdigit(int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char set);
long	ft_atol(char *str);
t_stack	*ft_stacknew(int content);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	init_stack(char **av, t_stack **a);
void	move_a_to_b(t_stack **a, t_stack **b);
void	rot_min_to_top(t_stack **a);
void	rot_rrb_dir(t_stack **a, t_stack **b, t_stack *move);
void	rot_rb_dir(t_stack **a, t_stack **b, t_stack *move);
void	move_b_to_a(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	sortthree(t_stack **a);
int		*sort_rank(int *array, t_stack *a, int j);
void	set_rank(t_stack **a, int div, int j);
void	div_n_conq(t_stack **a, t_stack **b, t_stack *tmp_a, int i);
void	insertsort(t_stack **a, t_stack **b, int div);
void	free_stack(t_stack **a);
void 	free_str(char **new_av);
int		set_index_size(t_stack **a);
t_stack	*min_finder(t_stack *lst);
t_stack	*max_finder(t_stack *lst);
int		is_sorted(t_stack *lst);
int		set_target_b(t_stack **a, t_stack **b);
t_stack	*find_move(t_stack **b, int len_a, int len_b);
void	sortall(t_stack **a, t_stack **b);
int		invalid_error(char **new_av);
int		dup_error(char **new_av);
char	**tidy_input(char **av);

#endif
