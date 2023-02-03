/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:51:03 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/03 23:04:33 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stk(t_list **stack, int stk)
{
	int	tmp;
	int	index;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack)->value;
	index = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = index;
	if (stk == 1)
		printf("sa\n");
	if (stk == 2)
		printf("sb\n");
}

void	push_stk(t_list **fix, t_list **push, int stk)
{
	t_list	*tmp;

	if (!(*push))
		return ;
	tmp = (*push);
	ft_lstadd_front(fix, ft_lstnew((*push)->value, (*push)->index));
	(*push) = (*push)->next;
	free(tmp);
	if (stk == 1)
		printf("pa\n");
	if (stk == 2)
		printf("pb\n");
}

void	r_stk(t_list **s, int stk)
{
	t_list	*tmp;

	if (!(*s))
		return ;
	tmp = (*s);
	ft_lstadd_back(s, ft_lstnew((*s)->value, (*s)->index));
	(*s) = (*s)->next;
	free(tmp);
	if (stk == 1)
		printf("ra\n");
	if (stk == 2)
		printf("rb\n");
}

void	rr_stk(t_list **s, int stk)
{
	t_list	*b_last;
	t_list	*last;

	b_last = NULL;
	if (!(*s) || !((*s)->next))
		return ;
	last = *s;
	while (last->next)
	{
		b_last = last;
		last = last->next;
	}
	b_last->next = NULL;
	ft_lstadd_front(s, last);
	fill_indexes(s);
	if (stk == 1)
		printf("rra\n");
	if (stk == 2)
		printf("rrb\n");
}
