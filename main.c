#include "push_swap.h"

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