/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:40:39 by long              #+#    #+#             */
/*   Updated: 2023/12/20 12:52:36 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ABS(x) (x < 0) ? -x : x
# define MIN(x, y) (x < y) ? x : y
# define MAX(x, y) (x < y) ? y : x
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <fcntl.h>
# include <ctype.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

# if defined (__linux__)
#  define PTRNULL "(nil)"
# elif defined (__APPLE__)
#  define PTRNULL "0x0"
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_gnl
{
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

typedef struct s_flags
{
	int	type;
	int	left;
	int	space;
	int	plus;
	int	zero;
	int	hash;
	int	dot;
	int	width;
	int	precision;
}		t_flags;

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

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s11, const char *s22, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle,
			size_t len);
char	*ft_strrchr(char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));			
int		ft_print_ptr(void *i, t_flags flag);
int		ft_print_ux(unsigned int i, t_flags flag);
int		ft_print_int(int i, t_flags flag);
t_flags	ft_flags_init(void);
char	*ft_htoa(unsigned long long n, int i);
int		ft_putchar_len(char i);
int		ft_putstr_len(char *i);
int		ft_putpad_len(char i, int len);
int		ft_print_char(char i, t_flags flag);
int		ft_print_str(char *i, t_flags flag);
int		ft_printf(const char *format, ...);
t_gnl	*ft_lstlast_gnl(t_gnl *lst);
void	ft_lstadd_back_gnl(t_gnl **lst, t_gnl *new);
int		ft_lstsize_gnl(t_gnl *lst);
void	make_new(t_gnl **bufstr, char *str);
void	clean_list(t_gnl **bufstr);
char	*fill_letter(t_gnl *bufstr, int len);
char	*get_line(t_gnl *bufstr);
int		found_nl(t_gnl **bufstr);
void	create_list(int fd, t_gnl **bufstr);
char	*get_next_line(int fd);

#endif
