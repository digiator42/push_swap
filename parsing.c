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

int parsing(int ac, char **av)
{
	t_list *stack_a = NULL;
	static char *str;
	int i;
	if(ac <= 1)
		return 0;
	i = 1;
	while (av[i])
		str = ft_strjoin(str, av[i++]);
	av = ft_split(str, ' ');
	int j = 0;
	while (j < i - 1)
		if(av[j++] == NULL)
			return 0;
	if (!is_valid_num(av) || !is_not_dup(av) || !is_not_max(av))
		return 0;
	i = 0;
	stack_a = ft_lstnew(ft_atoi(*av++));
	while(*av)
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(*av++)));
	// print_stack(stack_a);
	if(is_sorted(stack_a))
		printf("sorted!\n");
	else{	
		swap_stack(&stack_a, 'a');
		printf("fist %d, second %d\n", stack_a->value, stack_a->next->value);
	}
	print_stack(stack_a);
	free(stack_a);
	return 1;
}