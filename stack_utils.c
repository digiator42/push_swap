/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:50:04 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/03 23:09:31 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (stack)
	{
		printf("|%d  -  %d|\n", stack->value, stack->index);
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

void	ft_free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
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
