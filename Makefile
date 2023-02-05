NAME = push_swap.a

SRCS = main.c				\
       parsing.c			\
	   sorting.c			\
	   sort_hlpr.c			\
	   push_swap_utils.c	\
	   list_utils.c			\
	   stack_utils.c		\
	   utils.c				\
	   ops.c				\
	   ft_printf/ft_format.c	        \
	   ft_printf/ft_printpointer.c	\
	   ft_printf/ft_putchar.c	        \
	   ft_printf/ft_putstr.c	        \
	   ft_printf/ft_printf.c	        \
	   ft_printf/ft_printhex.c	    \
	   ft_printf/ft_printunsigned.c	\
	   ft_printf/ft_putnbr.c	

EXEC = push_swap

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g3 -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(NAME) -o push_swap

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean all