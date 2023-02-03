#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list{
	int value;
	int index;
	struct s_list *next;
} t_list;

int add_stack(char **av);
void	sort_wise(t_list **stack_a, int len);
int 	parsing(int ac, char **av);
void	fill_indexes(t_list **list);
void ft_free_av(char **av);
void ft_free_stack(t_list *head);
void push_and_sort(t_list **stack_a, t_list **stack_b);
long int	ft_atoi(char *ptr);
char	*ft_strjoin(char *str, char *av);
int is_space(char *str);
int	ft_strcmp(char *s1, char *s2);
char	**ft_split(char *s, char c);
t_list	*ft_lstnew(int content, int index);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_b_node(t_list *lst);
int	ft_lstsize(t_list *lst);
void print_stack(t_list *stack);
int is_sorted(t_list *stack);
void swap_stk(t_list **stack, int stk);
void push_stk(t_list **fix, t_list **push, int stk);
void r_stk(t_list **s, int stk);
void rr_stk(t_list **s, int stk);
void ss(t_list **stack_a, t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);
#endif