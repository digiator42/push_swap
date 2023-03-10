/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:49:58 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/05 17:48:08 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	add_stack(char **av)
{
	int		i;
	t_list	*stack_a;

	i = 0;
	stack_a = ft_lstnew(ft_atoi(av[i]), i);
	while (av[++i])
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(av[i]), i));
	ft_free_av(av);
	if (is_sorted(stack_a))
		(ft_free_stack(stack_a), ft_printf("sorted!\n"), exit(0));
	fill_indexes(&stack_a);
	sort_wise(&stack_a, i);
	ft_free_stack(stack_a);
}

int	main(int ac, char **av)
{
	static char	*str;
	int			i;

	if (ac <= 1)
		return (0);
	i = 0;
	while (++i < ac)
		if (!ft_strcmp(av[i], "") || !is_space(av[i]))
			return (ft_printf("\x1B[31mError\n"), 0);
	i = 1;
	while (av[i])
		str = ft_strjoin(str, av[i++]);
	av = ft_split(str, ' ');
	free(str);
	if (!is_valid_num(av) || !is_not_dup(av) || !is_not_max(av))
		return (ft_free_av(av), ft_printf("\x1B[31mError\n"), 0);
	add_stack(av);
	return (0);
}
