/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:51:09 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/05 17:49:02 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

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
