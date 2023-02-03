#include "push_swap.h"

void swap_stk(t_list **stack, int stk)
{
	int tmp;
	int index;
	if(!(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack)->value;
	index = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = index;
	if(stk == 1)
		printf("sa\n");
	if(stk == 2)	
		printf("sb\n");
}

void push_stk(t_list **fix, t_list **push, int stk)
{
	if(!(*push))
		return ;
	t_list *tmp = (*push);
	ft_lstadd_front(fix, ft_lstnew((*push)->value, (*push)->index));
	(*push) = (*push)->next;
	free(tmp);
	if(stk == 1)
		printf("pa\n");
	if(stk == 2)	
		printf("pb\n");
}

void r_stk(t_list **s, int stk)
{
	if(!(*s))
		return ;
	t_list *tmp = (*s);	
	ft_lstadd_back(s, ft_lstnew((*s)->value, (*s)->index));
	(*s) = (*s)->next;
	free(tmp);
	if(stk == 1)
		printf("ra\n");
	if(stk == 2)	
		printf("rb\n");
}

void rr_stk(t_list **s, int stk)
{
	t_list *b_last = NULL;
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
	fill_indexes(s);
	if(stk == 1)
		printf("rra\n");
	if(stk == 2)	
		printf("rrb\n");
}

void ss(t_list **stack_a, t_list **stack_b)
{
	swap_stk(stack_a, 0);
	swap_stk(stack_b, 0);
	printf("ss\n");
}

void rr(t_list **stack_a, t_list **stack_b)
{
	r_stk(stack_a, 0);
	r_stk(stack_b, 0);
	printf("rr\n");
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	rr_stk(stack_a, 0);
	rr_stk(stack_b, 0);
	printf("rrr\n");
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

// 	print_stack(lst2);
// 	printf("\n");
// 	print_stack(lst);
// 	push_stk(&lst, &lst2, 1);
// 	print_stack(lst2);
// 	printf("\n");
// 	print_stack(lst);
// }