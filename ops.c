#include "push_swap.h"

void swap_stk(t_list **stack, int stk)
{
	int tmp;
	int index;
	tmp = (*stack)->value;
	index = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = index;
	if(stk == 1)
		printf("sa\n");
	else	
		printf("sb\n");
}

void push_stk(t_list **fix, t_list **push, int stk)
{
	ft_lstadd_front(fix, ft_lstnew((*push)->value, (*push)->index));
	(*push) = (*push)->next;
	if(stk == 1)
		printf("pa\n");
	else	
		printf("pb\n");
}

void r_stk(t_list **s, int stk)
{
	if(!(*s))
		return ;
	ft_lstadd_back(s, ft_lstnew((*s)->value, (*s)->index));
	(*s) = (*s)->next;
	if(stk == 1)
		printf("ra\n");
	else	
		printf("rb\n");
}

void rr_stk(t_list **s, int stk)
{
	t_list *b_last;
	t_list *last;
	
	if(!(*s) || !((*s)->next))
		return ;
	last = *s;
	while(last->next){
		b_last = last;
		last = last->next;
	}
	b_last->next = NULL;
	// last->next = *s;
	// *s = last;
	ft_lstadd_front(s, last);
	if(stk == 1)
		printf("rra\n");
	else	
		printf("rrb\n");
}


// int main()
// {
// 	int i = 0;
// 	t_list *lst;
// 	t_list *tmp;
// 	t_list *tmp2;
// 	int c[] = {1, 2, 3, 4};
// 	size_t len = sizeof(c) / sizeof(c[0]);
// 	int j = 0;
// 	lst = ft_lstnew(c[i++], j++);
// 	while (i < len)
// 		ft_lstadd_back(&lst, ft_lstnew(c[i++], j++));
// 	i = 0;	
// 	t_list *lst2;
// 	int c2[] = {5, 6, 7, 8};
// 	j = 0;
// 	lst2 = ft_lstnew(c2[i++], j++);
// 	while (i < len)
// 		ft_lstadd_back(&lst2, ft_lstnew(c2[i++], j++));

// 	print_stack(lst);
// 	print_stack(lst2);
// }