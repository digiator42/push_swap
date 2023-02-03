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

int add_stack(char **av)
{
	int i;
	t_list *stack_a;
	
	i = 0;
	stack_a = ft_lstnew(ft_atoi(av[i]), i);
	while(av[++i])
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(av[i]), i));
	ft_free_av(av);	
	if(is_sorted(stack_a))
		return (ft_free_stack(stack_a), printf("sorted!\n"));
	fill_indexes(&stack_a);
	sort_wise(&stack_a, i);
	ft_free_stack(stack_a);
	return 1;
}

int main(int ac, char **av)
{
	if(!parsing(ac, av))
		write(2, "\x1B[31mError\n", 12);
}