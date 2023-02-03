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
	{
		rr_stk(stack_a, 1);
	}
}

int find_index(t_list *lst)
{
	int	len;
	int	i;

	len = ft_lstsize(lst);
	i = 0;
	while (lst)
	{
		if(lst->index == 0)
			return i;
		lst = lst->next;
		i++;
	}
	return (i);
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

void	sort_few(t_list **stack_a, t_list **stack_b, int len)
{
	int smallest = find_index(*stack_a);
	if(smallest <= len / 4)
	{
		if((*stack_a)->index == 0)
		{
			push_stk(stack_b, stack_a, 2);
			fill_indexes(stack_a);
		}
		else
			r_stk(stack_a, 1);
	}
	else
	{
		if(ft_lstlast(*stack_a)->index == 0)
		{
			rr_stk(stack_a, 1);
			push_stk(stack_b, stack_a, 2);
			fill_indexes(stack_a);
		}
		else
			rr_stk(stack_a, 1);
	}
}

void sort_bunch(t_list **stack_a, t_list **stack_b, int len)
{
	while (len)
	{
		if ((*stack_a)->index % 2 == 1)
		{	
			(*stack_a)->index /= 2;
			r_stk(stack_a, 1);
		}
		else if ((*stack_a)->index % 2 == 0)
		{	
			(*stack_a)->index /= 2;
			push_stk(stack_b, stack_a, 2);
		}
		len--;
	}
}

void	sort_wise(t_list **stack_a, int len)
{
	t_list *stack_b = NULL;
	if(len == 1)
		return ;
	if(len == 2)
		swap_stk(stack_a, 1);
	if(len == 3)
		sort_three(stack_a);
	if(len == 4)
		sort_four(stack_a, &stack_b);
	if(len == 5)
		sort_five(stack_a, &stack_b);
	else if (len <= 50)
	{
		while (!is_sorted(*stack_a))
			sort_few(stack_a, &stack_b, len);
		while (stack_b)
			push_stk(stack_a, &stack_b, 2);
	}
	else
	{
		while (!is_sorted(*stack_a))
		{
			sort_bunch(stack_a, &stack_b, len);
			while (stack_b)
				push_stk(stack_a, &stack_b, 2);
		}
	}
	// print_stack(*stack_a);	
}