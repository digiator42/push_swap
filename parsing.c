/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:51:09 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/03 23:07:04 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_num(char **av)
{
	int	i;
	int	j;

	j = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (i == 0)
				if ((av[j][0] == '+' || av[j][0] == '-'))
					i++;
			if (av[j][i] >= '0' && av[j][i] <= '9')
				i++;
			else
			{
				return (0);
			}
		}
		j++;
	}
	return (1);
}

int	is_not_dup(char **strs)
{
	int	i;
	int	j;

	i = -1;
	while (strs[++i])
	{
		j = i + 1;
		while (strs[j])
			if (ft_atoi(strs[i]) == ft_atoi(strs[j++]))
				return (0);
	}
	return (1);
}

int	ft_atoi_max(char *str)
{
	long int	num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	is_not_max(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		if (!ft_atoi_max(strs[i]))
			return (0);
	return (1);
}

int	parsing(int ac, char **av)
{
	static char	*str;
	int			i;

	if (ac <= 1)
		return (-1);
	i = 0;
	while (++i < ac)
		if (!ft_strcmp(av[i], "") || !is_space(av[i]))
			return (0);
	i = 1;
	while (av[i])
		str = ft_strjoin(str, av[i++]);
	av = ft_split(str, ' ');
	free(str);
	if (!is_valid_num(av) || !is_not_dup(av) || !is_not_max(av))
		return (ft_free_av(av), 0);
	if (add_stack(av))
		return (1);
	return (1);
}
