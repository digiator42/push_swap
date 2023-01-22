#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list{
	int value;
	struct s_list *next;
} t_list;

int	parsing(int ac, char **av);
long int	ft_atoi(char *ptr);
char	*ft_strjoin(char *str, char *av);
char	**ft_split(char *s, char c);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void print_stack(t_list *stack);
int is_sorted(t_list *stack);


#endif