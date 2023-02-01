#include "push_swap.h"

void print_stack(t_list *stack)
{
	t_list *tmp;
	tmp = stack;
	while(stack)
	{
		printf("|%d - %d|", stack->value, stack->index);
		// sleep(1);
		stack = stack->next;
	}
	stack = tmp;
	printf("\n");
}

int is_sorted(t_list *stack)
{
	if(stack == NULL || stack->next == NULL)
		return 0;
	while(stack->next)
	{
		if(stack->value > stack->next->value)
				return 0;
		stack = stack->next;
	}
	return 1;
}