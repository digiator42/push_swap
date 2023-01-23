#include "push_swap.h"

void swap_stack(t_list **stack, char stk)
{
	int tmp;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	if(stk == 'a')
		printf("sa\n");
	else	
		printf("sb\n");
}

void pa(t_list **a, t_list **b)
{
	ft_lstadd_front(b, ft_lstnew((*a)->value));
	(*a) = (*a)->next;
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