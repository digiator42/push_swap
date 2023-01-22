#include "push_swap.h"

void print_stack(t_list *stack)
{
	while(stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int is_sorted(t_list *stack)
{
	while(stack->next)
	{
		if(stack->value > stack->next->value)
				return 0;
		stack = stack->next;
	}
	return 1;
}