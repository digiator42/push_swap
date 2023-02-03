#include "push_swap.h"

void sort_three(t_list **stack_a)
{
	fill_indexes(stack_a);

	if((*stack_a)->index == 2 && (*stack_a)->next->index == 0)
		r_stk(stack_a, 1);
	else if((*stack_a)->index == 1 && (*stack_a)->next->index == 0)
		swap_stk(stack_a, 1);
	else if((*stack_a)->index == 2 && (*stack_a)->next->index == 1)
	{
		swap_stk(stack_a, 1);
		rr_stk(stack_a, 1);
	}
	else if((*stack_a)->index == 0 && (*stack_a)->next->index == 2)
	{
		swap_stk(stack_a, 1);
		r_stk(stack_a, 1);
	}
	else if((*stack_a)->index == 1 && (*stack_a)->next->index == 2)
		rr_stk(stack_a, 1);
}

void push_and_sort(t_list **stack_a, t_list **stack_b)
{
		push_stk(stack_b, stack_a, 2);
		sort_three(stack_a);
		push_stk(stack_a, stack_b, 1);
}

void sort_four(t_list **stack_a, t_list **stack_b)
{
	fill_indexes(stack_a);
	if(0 == ((*stack_a)->index))
		push_and_sort(stack_a, stack_b);
	else if(0 == ((*stack_a)->next->index))
	{
		swap_stk(stack_a, 1);
		push_and_sort(stack_a, stack_b);
	}
	else if(0 == (ft_lstlast(*stack_a)->index))
	{
		rr_stk(stack_a, 1);
		push_and_sort(stack_a, stack_b);
	}
	else
	{
		rr_stk(stack_a, 1);
		rr_stk(stack_a, 1);
		push_and_sort(stack_a, stack_b);
	}
}

void push_and_sort2(t_list **stack_a, t_list **stack_b)
{
		push_stk(stack_b, stack_a, 2);
		sort_four(stack_a, stack_b);
		push_stk(stack_a, stack_b, 1);
}

void sort_five(t_list **stack_a, t_list **stack_b)
{
	fill_indexes(stack_a);
	if(0 == ((*stack_a)->index))
		push_and_sort2(stack_a, stack_b);
	else if(0 == ((*stack_a)->next->index))
	{
		swap_stk(stack_a, 1);
		push_and_sort2(stack_a, stack_b);
	}
	else if(0 == (ft_lstlast(*stack_a)->index))
	{
		rr_stk(stack_a, 1);
		push_and_sort2(stack_a, stack_b);
	}
	else if (0 == (ft_b_node(*stack_a)->index))
	{
		rr_stk(stack_a, 1);
		rr_stk(stack_a, 1);
		push_and_sort2(stack_a, stack_b);
	}
	else
	{
		r_stk(stack_a, 1);
		r_stk(stack_a, 1);
		push_and_sort2(stack_a, stack_b);
	}
}