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

// void pa(t_list **stack, char stk)
// {
	
// }

