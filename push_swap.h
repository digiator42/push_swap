/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:50:10 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/05 16:45:33 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

void				add_stack(char **av);
int					is_space(char *str);
int					ft_strcmp(char *s1, char *s2);
void				sort_wise(t_list **stack_a, int len);
int					parsing(int ac, char **av);
void				fill_indexes(t_list **list);
int					find_index(t_list *lst);
void				ft_free_av(char **av);
void				ft_free_stack(t_list *head);
void				push_and_sort(t_list **stack_a, t_list **stack_b);
long int			ft_atoi(char *ptr);
char				*ft_strjoin(char *str, char *av);
int					is_space(char *str);
int					ft_strcmp(char *s1, char *s2);
char				**ft_split(char *s, char c);
t_list				*ft_lstnew(int content, int index);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_b_node(t_list *lst);
int					ft_lstsize(t_list *lst);
void				print_stack(t_list *stack);
int					is_sorted(t_list *stack);
void				ft_free_av(char **av);
void				ft_free_stack(t_list *head);
void				swap_stk(t_list **stack, int stk);
void				push_stk(t_list **fix, t_list **push, int stk);
void				r_stk(t_list **s, int stk);
void				rr_stk(t_list **s, int stk);
void				sort_three(t_list **stack_a);
void				sort_four(t_list **stack_a, t_list **stack_b);
void				sort_five(t_list **stack_a, t_list **stack_b);
int					is_not_max(char **strs);
int					is_not_dup(char **strs);
int					is_valid_num(char **av);
#endif