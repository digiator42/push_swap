/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:50:04 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/05 17:48:55 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (stack)
	{
		ft_printf("|%d  -  %d|\n", stack->value, stack->index);
		stack = stack->next;
	}
	stack = tmp;
}

int	is_sorted(t_list *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (0);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_index(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->index == 0)
			return (i);
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_b_node(t_list *lst)
{
	t_list	*b_last;

	if (!lst)
		return (0);
	while (lst->next)
	{
		b_last = lst;
		lst = lst->next;
	}
	return (b_last);
}

void	ft_free_stack(t_list *head)
{
	t_list	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
