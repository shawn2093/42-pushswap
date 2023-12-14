NAME = push_swap
LIBFTNAME = libft.a
CC = gcc
AR = ar -rc
RM = rm -f
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isalnum.c \
		ft_isdigit.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		ft_printf.c ft_print_num.c ft_print_str.c ft_printf_utils.c \
		get_next_line.c get_next_line_utils.c
FILE = pushswap.c
			
CFLAGS = -Wall -Wextra -Werror
OPTION = -I ./

OBJS = $(SRCS:.c=.o)
FILS = $(FILE:.c=.o)

all: $(NAME)

$(NAME): $(LIBFTNAME)
	$(CC) $(CFLAGS) $(FILE)
	$(CC) $(LIBFTNAME) $(FILS) -o $(NAME)

$(LIBFTNAME): $(OBJS)
	$(AR) $(LIBFTNAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
