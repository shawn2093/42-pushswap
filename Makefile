NAME1 = push_swap
NAME2 = checker
CC = gcc
RM = rm -f
SRCS = ft_split.c ft_strdup.c ft_isdigit.c ft_strjoin.c ft_strlen.c \
		ft_atol.c stack_utils.c move_utils.c oper_utils_1.c oper_utils_2.c \
		oper_utils_3.c algo.c check_utils.c sort_utils.c free_utils.c \
		get_next_line.c get_next_line_utils.c
MAND = pushswap.c
BONS = checker.c checker_utils.c
			
CFLAGS = -Wall -Wextra -Werror
OPTION = -I ./

SRCS_OBJS = $(SRCS:.c=.o)

MAND_OBJS = $(MAND:.c=.o)

BONS_OBJS = $(BONS:.c=.o)

all: $(NAME1)

$(NAME1): $(SRCS_OBJS) $(MAND_OBJS)
	$(CC) $(CFLAGS) $(SRCS_OBJS) $(MAND_OBJS) $(OPTION) -o $@

$(NAME2): $(SRCS_OBJS) $(BONS_OBJS)
	$(CC) $(CFLAGS) $(SRCS_OBJS) $(BONS_OBJS) $(OPTION) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

clean:
	$(RM) $(SRCS_OBJS)
	$(RM) $(MAND_OBJS)
	$(RM) $(BONS_OBJS)

fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re: fclean all bonus

bonus: $(NAME2)

.PHONY: all clean fclean re
