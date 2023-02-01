#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(int content, int index)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->value = content;
	new->index = index;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next){
		lst = lst->next;
	}
	return (lst);
}

t_list	*ft_b_node(t_list *lst, t_list **b_last)
{
	if (!lst)
		return (0);
	while (lst->next){
		b_last = &lst;
		lst = lst->next;
	}
	(*b_last)->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast((*lst));
			tmp->next = new;
		}
	}
}