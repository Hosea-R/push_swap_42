SRCS = configure_mq.c convert.c errors.c free.c free_input.c free_ressouces.c ft_atoi.c ft_split.c ft_strdup.c ft_strlen.c get.c initialize_launch_stack.c initialize_process_input.c mediane_calculation.c optimization.c push_ab.c push_swap.c quick_sort.c reverse_rotate.c rotate.c setup_mediane_quartile.c sort_three.c split_free.c swap.c utils.c utils_algo.c validate_input.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all: $(NAME)
.c.o:
		cc $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
		cc $(CFLAGS) $(OBJS) -o $(NAME)
clean:
		rm -f $(OBJS)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
