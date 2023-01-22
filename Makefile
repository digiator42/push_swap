NAME = push_swap

SRCS = main.c				\
       parsing.c			\
	   push_swap_utils.c	\
	   stack_utils.c		\
	   ft_split.c			\
	   ops.c				\
	   ft_lstnew.c			\
	   ft_lstadd_back.c		\
	   ft_lstlast.c			\
	   
OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all