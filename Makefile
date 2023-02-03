NAME = push_swap

SRCS = main.c				\
       parsing.c			\
	   sorting.c			\
	   sort_hlpr.c			\
	   push_swap_utils.c	\
	   list_utils.c			\
	   stack_utils.c		\
	   utils.c				\
	   ops.c				\
	   
OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all