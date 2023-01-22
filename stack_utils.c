#include "push_swap.h"

void print_stack(t_list *stack)
{
	while(stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
}