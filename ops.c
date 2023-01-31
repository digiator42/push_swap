#include "push_swap.h"

void swap_stk(t_list **stack, int stk)
{
	int tmp;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	if(stk == 1)
		printf("sa\n");
	else	
		printf("sb\n");
}

void push_stk(t_list **fix, t_list **push, int stk)
{
	ft_lstadd_front(fix, ft_lstnew((*push)->value));
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
	ft_lstadd_back(s, ft_lstnew((*s)->value));
	(*s) = (*s)->next;
	if(stk == 1)
		printf("ra\n");
	else	
		printf("rb\n");
}


// int main()
// {
// 	int i = 0;
// 	t_list *lst;
// 	t_list *tmp;
// 	t_list *tmp2;
// 	int c[] = {1, 2, 3, 4};
// 	lst = ft_lstnew(c[i++]);
// 	while (i < 4)
// 		ft_lstadd_back(&lst, ft_lstnew(c[i++]));
// 	i = 0;	
// 	t_list *lst2;
// 	int c2[] = {5, 6, 7, 8};
// 	lst2 = ft_lstnew(c2[i++]);
// 	while (i < 4)
// 		ft_lstadd_back(&lst2, ft_lstnew(c2[i++]));

// 	print_stack(lst);
// 	print_stack(lst2);
// 	pb_move(&lst, &lst2);
// 	print_stack(lst);
// 	print_stack(lst2);
// }