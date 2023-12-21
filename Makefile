NAME = push_swap
LIBFTNAME = libft.a
CC = gcc
AR = ar -rc
RM = rm -f
SRCS = ft_split.c ft_strdup.c ft_isdigit.c ft_strjoin.c ft_strlen.c \
		ft_atol.c stack_utils.c move_utils.c oper_utils_1.c oper_utils_2.c \
		oper_utils_3.c algo.c check_utils.c sort_utils.c pushswap.c
			
CFLAGS = -Wall -Wextra -Werror
# OPTION = -I ./ -fsanitize=address -g3
OPTION = -I ./

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(OPTION) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
