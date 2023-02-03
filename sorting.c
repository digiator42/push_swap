/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:50:01 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/03 23:08:16 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min(t_list **stack_a, t_list **stack_b, int len)
{
	if (len == 2)
		swap_stk(stack_a, 1);
	if (len == 3)
		sort_three(stack_a);
	if (len == 4)
		sort_four(stack_a, stack_b);
	if (len == 5)
		sort_five(stack_a, stack_b);
}

void	sort_few(t_list **stack_a, t_list **stack_b, int len)
{
	int	smallest;

	smallest = find_index(*stack_a);
	if (smallest <= len / 3)
	{
		if ((*stack_a)->index == 0)
		{
			push_stk(stack_b, stack_a, 2);
			fill_indexes(stack_a);
		}
		else
			r_stk(stack_a, 1);
	}
	else
	{
		if (ft_lstlast(*stack_a)->index == 0)
		{
			rr_stk(stack_a, 1);
			push_stk(stack_b, stack_a, 2);
			fill_indexes(stack_a);
		}
		else
			rr_stk(stack_a, 1);
	}
}

void	sort_bunch(t_list **stack_a, t_list **stack_b, int len)
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
	t_list	*stack_b;

	stack_b = NULL;
	if (len >= 1 && len <= 5)
		sort_min(stack_a, &stack_b, len);
	else if (len <= 50)
	{
		while (!is_sorted(*stack_a))
			sort_few(stack_a, &stack_b, len);
		while (stack_b)
			push_stk(stack_a, &stack_b, 1);
	}
	else
	{
		while (!is_sorted(*stack_a))
		{
			len = ft_lstsize(*stack_a);
			sort_bunch(stack_a, &stack_b, len);
			while (stack_b)
				push_stk(stack_a, &stack_b, 1);
		}
	}
}
