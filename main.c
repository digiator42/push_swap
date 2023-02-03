/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:49:58 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/03 23:03:39 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	fill_indexes(t_list **list)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;

	i = 0;
	tmp = (*list);
	while (tmp)
	{
		i = 0;
		tmp2 = (*list);
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				i++;
			tmp2 = tmp2->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
}

int	add_stack(char **av)
{
	int		i;
	t_list	*stack_a;

	i = 0;
	stack_a = ft_lstnew(ft_atoi(av[i]), i);
	while (av[++i])
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(av[i]), i));
	ft_free_av(av);
	if (is_sorted(stack_a))
		return (ft_free_stack(stack_a), printf("sorted!\n"));
	fill_indexes(&stack_a);
	sort_wise(&stack_a, i);
	ft_free_stack(stack_a);
	return (1);
}

int	main(int ac, char **av)
{
	if (!parsing(ac, av))
		write(2, "\x1B[31mError\n", 12);
}
