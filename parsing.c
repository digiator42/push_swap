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
			if(i == 0)
				if ((av[j][0] == '+' || av[j][0] == '-' ))
					i++;
			if (av[j][i] >= '0' && av[j][i] <= '9')
				i++;
			else{
				return (0);
			}
		}
		j++;
	}
	return (1);
}

int is_not_dup(char **strs)
{
	int i = -1;
	while(strs[++i])
	{
		int j = i + 1;
		while(strs[j])
			if(ft_atoi(strs[i]) == ft_atoi(strs[j++]))
					return 0;
	}
	return 1;
}

int	ft_atoi_max(char *str)
{
	long int num = ft_atoi(str);
	if(num > INT_MAX || num < INT_MIN)
		return 0;	
	return 1;
}

int is_not_max(char **strs)
{
	int i = -1;
	while(strs[++i])
		if(!ft_atoi_max(strs[i]))
			return 0;
	return 1;
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

void ft_free_av(char **av)
{
	int i = 0;
	while (av[i])
		free(av[i++]);
	free(av);	
}

void ft_free_stack(t_list *head)
{
   t_list *tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

int parsing(int ac, char **av)
{
	static char *str;
	int i;
	if(ac <= 1)
		return -1;
	i = 0;
	while (++i < ac)
		if(!ft_strcmp(av[i], "") || !is_space(av[i]))
			return 0;
	i = 1;
	while (av[i])
		str = ft_strjoin(str, av[i++]);
	av = ft_split(str, ' ');
	free(str);
	if (!is_valid_num(av) || !is_not_dup(av) || !is_not_max(av))
		return (ft_free_av(av), 0);
	if(add_stack(av))
		return 1;	
	return (1);
}
