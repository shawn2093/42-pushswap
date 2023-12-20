/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:13:32 by long              #+#    #+#             */
/*   Updated: 2023/12/20 18:30:14 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char set)
{
	if (c == set)
		return (1);
	return (0);
}

static int	word_count(char const *str, char set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], set))
			i++;
		if (str[i] && !is_sep(str[i], set))
			count++;
		while (str[i] && !is_sep(str[i], set))
			i++;
	}
	return (count);
}

static char	*fill_letters(char const *str, char set)
{
	char	*newstr;
	int		i;

	i = 0;
	while (!is_sep(str[i], set) && str[i])
		i++;
	newstr = (char *)malloc((i + 1) * sizeof(char));
	if (!newstr)
		return (0);
	i = 0;
	while (!is_sep(str[i], set) && str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	**ft_split(char const *s, char set)
{
	char	**split_str;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	count = word_count(s, set);
	split_str = (char **)malloc((count + 1) * sizeof(char *));
	if (!split_str)
		return (0);
	while (*s)
	{
		while (*s && is_sep(*s, set))
			s++;
		if (*s)
		{
			split_str[i] = fill_letters(s, set);
			i++;
			while (*s && !is_sep(*s, set))
				s++;
		}
	}
	split_str[i] = 0;
	return (split_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*str;
	int		i;
	int		j;

	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && s2)
		return ((char *)s2);
	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(total_len * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}

long	ft_atol(char *str)
{
	long	minus_num;
	long	res;

	minus_num = 1;
	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
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

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	j = -1;
	while (s1[i])
		i++;
	t = malloc((i + 1) * sizeof(char));
	if (!t)
		return (0);
	while (s1[++j])
	{
		t[j] = s1[j];
	}
	t[j] = '\0';
	return (t);
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

void	free_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*a = NULL;
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = NULL;
	if (!*a)
		*a = tmp;
	else
		ft_stackadd_front(a, tmp);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = NULL;
	if (!*b)
		*b = tmp;
	else
		ft_stackadd_front(b, tmp);
	write(1, "pb\n", 3);
}

void	ra(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	(*a)->prev = NULL;
	ft_stackadd_back(a, tmp);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	(*b)->prev = NULL;
	ft_stackadd_back(b, tmp);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

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

void	rra(t_stack **a)
{
	t_stack	*tmp;

	tmp = ft_stacklast(*a);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_stackadd_front(a, tmp);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	tmp = ft_stacklast(*b);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	ft_stackadd_front(b, tmp);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

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

void	sa(t_stack **a)
{
	int	tmp;

	tmp = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int	tmp;

	tmp = (*b)->number;
	(*b)->number = (*b)->next->number;
	(*b)->next->number = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	int	tmp;

	tmp = (*a)->number;
	(*a)->number = (*a)->next->number;
	(*a)->next->number = tmp;
	tmp = (*b)->number;
	(*b)->number = (*b)->next->number;
	(*b)->next->number = tmp;
	write(1, "ss\n", 3);
}

int	set_index_size(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->index = i;
		tmp->target = -1;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	sortthree(t_stack **a)
{
	int	first;
	int	second;
	int	third;

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

t_stack	*min_finder(t_stack *lst)
{
	int		min;
	t_stack	*tmp;

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

t_stack	*max_finder(t_stack *lst)
{
	int		max;
	t_stack	*tmp;

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

void set_rank(t_stack **a)
{
	int 	*array;
	int		i;
	int		j;
	int		k;
	int		tmp;
	t_stack	*tmp_a;

	j = set_index_size(a);
	tmp_a = *a;
	array = (int *)malloc(sizeof(int) * j);
	if (!array)
		return ;
	i = -1;
	while (++i < j)
	{
		array[i] = tmp_a->number;
		tmp_a = tmp_a->next;
	}
	i = -1;
	while (++i < j)
	{
		k = i;
		while (++k < j)
		{
			if (array[i] > array[k])
			{
				tmp = array[i];
				array[i] = array[k];
				array[k] = tmp;
			}
		}
	}
	tmp_a = *a;
	while (tmp_a)
	{
		i = -1;
		while (++i < j)
		{
			if (tmp_a->number == array[i])
				tmp_a->rank = i;
		}
		tmp_a = tmp_a->next;
	}
	tmp_a = *a;
	i = set_index_size(a) / 5;
	if (i * 5 != set_index_size(a))
		i++;
	while (tmp_a)
	{
		tmp_a->rank = tmp_a->rank / i;
		tmp_a = tmp_a->next;
	}
	free(array);
}

void	set_target_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	while (tmp_a)
	{
		tmp_b = *b;
		while (tmp_b)
		{
			if (tmp_a->number > tmp_b->number && !tmp_b->prev
				&& tmp_a->number < ft_stacklast(*b)->number)
				tmp_a->target = tmp_b->index;
			if (tmp_a->number > tmp_b->number && tmp_b->prev
				&& tmp_a->number < tmp_b->prev->number)
				tmp_a->target = tmp_b->index;
			tmp_b = tmp_b->next;
		}
		tmp_b = max_finder(*b);
		if (tmp_a->target == -1 && (tmp_a->number > tmp_b->number
				|| tmp_a->number < min_finder(*b)->number))
			tmp_a->target = tmp_b->index;
		tmp_a = tmp_a->next;
	}
}
t_stack *find_move(t_stack **a, int len_a, int len_b)
{
    t_stack	*tmp_a;
	t_stack	*move;
    int		move_a;
	int		move_b;
    
    tmp_a = *a;
    while (tmp_a)
    {
        move_a = MIN(tmp_a->index, len_a - tmp_a->index);
        move_b = MIN(tmp_a->target, len_b - tmp_a->target);
        tmp_a->cost = MAX(move_a, move_b);
        if ((move_a > len_a / 2 && move_b < len_b / 2)
            || (move_a < len_a / 2 && move_b > len_b / 2))
            tmp_a->cost = move_a + move_b;
        tmp_a = tmp_a->next;
    }
    tmp_a = *a;
    move = tmp_a;
    while (tmp_a)
    {
        if (tmp_a->cost < move->cost)
            move = tmp_a;
        tmp_a = tmp_a->next;
    }
    return (move);
}

void	insertsort(t_stack **a, t_stack **b)
{
	int		i;
	int		len_a;
	int		len_aa;
	t_stack	*tmp_a;
	t_stack	*move;

	i = 0;
	len_a = set_index_size(a);
	while (set_index_size(a) > 3 && !is_sorted(*a))
	// while (set_index_size(a) > 0)
	{
		len_aa = set_index_size(a);
		tmp_a = *a;
		while (tmp_a)
		{
			tmp_a->cost = MIN(tmp_a->index, len_aa - tmp_a->index);
			tmp_a = tmp_a->next;
		}
		tmp_a = *a;
		while (tmp_a->rank != i && tmp_a->next)
			tmp_a = tmp_a->next;
		if (tmp_a->rank != i)
			tmp_a = NULL;
		if (!tmp_a)
			i++;
		else
		{
			move = tmp_a;
			while (tmp_a)
			{
				if (tmp_a->rank == i && tmp_a->cost < move->cost)
					move = tmp_a;
				tmp_a = tmp_a->next;
			}
			if (move->index <= len_aa / 2)
			{
				while (move->index-- > 0)
					ra(a);
			}
			else
			{
				while (move->index++ < len_aa)
					rra(a);
			}
			pb(a, b);
		}
	}
}

void	sortall(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*move;
	t_stack	*max;
	t_stack	*min;
	int		len_a;
	int		len_b;
	int		move_a;
	int		move_b;

	if (set_index_size(a) == 3)
		sortthree(a);
	else if (set_index_size(a) == 2)
	{
		if ((*a)->number > (*a)->next->number)
			ra(a);
	}
	else
	{
		// insertsort(a, b);
		while (set_index_size(a) > 3 && set_index_size(b) < 2 && !is_sorted(*a))
			pb(a, b);
		while (set_index_size(a) > 3 && !is_sorted(*a))
		{
			len_a = set_index_size(a);
			len_b = set_index_size(b);
			set_target_a(a, b);
            move = find_move(a, len_a, len_b);
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
				while (move->index > 0 && move->target > 0)
				{
					rr(a, b);
					move->index--;
					move->target--;
				}
				while (move->index-- > 0)
					ra(a);
				while (move->target-- > 0)
					rb(b);
			}
			else if (move->index > len_a / 2 && move->target > len_b / 2)
			{
				while (move->index < len_a && move->target < len_b)
				{
					rrr(a, b);
					move->index++;
					move->target++;
				}
				while (move->index++ < len_a)
					rra(a);
				while (move->target++ < len_b)
					rrb(b);
			}
			pb(a, b);
		}
	}
	if (set_index_size(a) == 3)
		sortthree(a);
	while (set_index_size(b))
	{
		len_b = set_index_size(b);
		tmp_b = *b;
		while (tmp_b)
		{
			len_a = set_index_size(a);
			tmp_a = *a;
			while (tmp_a)
			{
				if (tmp_a->prev == NULL)
				{
					if (tmp_b->number < tmp_a->number
						&& tmp_b->number > ft_stacklast(*a)->number)
						tmp_b->target = tmp_a->index;
				}
				else
				{
					if (tmp_b->number < tmp_a->number
						&& tmp_b->number > tmp_a->prev->number)
						tmp_b->target = tmp_a->index;
				}
				tmp_a = tmp_a->next;
			}
			if (tmp_b->target == -1)
			{
				max = max_finder(*a);
				min = min_finder(*a);
				if (tmp_b->number > max->number || tmp_b->number < min->number)
					tmp_b->target = min->index;
			}
			tmp_b = tmp_b->next;
		}
		tmp_b = *b;
		while (tmp_b)
		{
			move_a = MIN(tmp_b->target, len_a - tmp_b->target);
			move_b = MIN(tmp_b->index, len_b - tmp_b->index);
			tmp_b->cost = MAX(move_a, move_b);
			if ((move_a > len_a / 2 && move_b < len_b / 2) || (move_a < len_a
					/ 2 && move_b > len_b / 2))
				tmp_b->cost = move_a + move_b;
			tmp_b = tmp_b->next;
		}
		tmp_b = *b;
		move = tmp_b;
		while (tmp_b->next)
		{
			if (tmp_b->next->cost < move->cost)
				move = tmp_b->next;
			tmp_b = tmp_b->next;
		}
		if (move->index > len_b / 2 && move->target <= len_a / 2)
		{
			while (move->index++ < len_b)
				rrb(b);
			while (move->target-- > 0)
				ra(a);
		}
		else if (move->index <= len_b / 2 && move->target > len_a / 2)
		{
            while (move->index-- > 0)
                rb(b);
            while (move->target++ < len_a)
                rra(a);
		}
		else if (move->index <= len_b / 2 && move->target <= len_a / 2)
		{
			while (move->index > 0 && move->target > 0)
			{
				rr(a, b);
				move->index--;
				move->target--;
			}
			while (move->index-- > 0)
				rb(b);
			while (move->target-- > 0)
				ra(a);
		}
		else if (move->index > len_b / 2 && move->target > len_a / 2)
		{
			while (move->index < len_b && move->target < len_a)
			{
				rrr(a, b);
				move->index++;
				move->target++;
			}
			while (move->index++ < len_b)
				rrb(b);
			while (move->target++ < len_a)
				rra(a);
		}
		pa(a, b);
	}
	set_index_size(a);
	min = min_finder(*a);
	while (min->index > 0 && min->index <= len_a / 2)
	{
		ra(a);
		min->index--;
	}
	while (min->index > len_a / 2 && min->index <= len_a)
	{
		rra(a);
		min->index++;
	}
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

int	main(int ac, char **av)
{
	int		i;
	char	**new_av;
	t_stack	*a;
	t_stack	*b;

	i = -1;
	if (ac >= 2)
	{
		if (ac == 2 && av[1][0] == '\0')
			return (write(2, "Error\n", 6));
		new_av = tidy_input(av);
		if (invalid_error(new_av) || dup_error(new_av))
			return (write(2, "Error\n", 6));
		a = NULL;
		b = NULL;
		init_stack(new_av, &a);
		set_rank(&a);
		sortall(&a, &b);
		// insertsort(&a, &b);
		// while (a)
		// {
		// 	printf("%d\n", a->number);
		// 	a = a->next;
		// }
		// while (b)
		// {
		// 	printf("%d\n", b->number);
		// 	b = b->next;
		// }
		i = -1;
		while (new_av[++i])
			free(new_av[i]);
		free(new_av);
		free_stack(&a);
	}
	return (0);
}
