NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = bench.c chunk_sort.c disorder.c dispatch.c flags.c ft_split.c \
	ft_strdup.c ft_strlen.c ft_substr.c index_stack.c main.c \
	operations_push.c operations_reverse_rotate.c operations_rotate.c \
	operations_swap.c parsing_one.c parsing_two.c radix_sort.c \
	selection_sort.c stack.c stack_utils.c tiny_sort.c \
	bench_utils.c puts_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
