#include "checker.h"
//#include <stdio.h>

//void 	stack_print(t_stack a, t_stack b);

int	ft_check_line(t_stack *a, t_stack *b, char *line)
{
	if (ft_strncmp(line, "sa") == 1)
		return (sa(a));
	else if (ft_strncmp(line, "sb") == 1)
		return (sb(b));
	else if (ft_strncmp(line, "ss") == 1)
		return (ss(a, b));
	else if (ft_strncmp(line, "pa") == 1)
		return (pa(a, b));
	else if (ft_strncmp(line, "pb") == 1)
		return (pb(a, b));
	else if (ft_strncmp(line, "ra") == 1)
		return (ra(a));
	else if (ft_strncmp(line, "rb") == 1)
		return (rb(b));
	else if (ft_strncmp(line, "rr") == 1)
		return (rr(a, b));
	else if (ft_strncmp(line, "rra") == 1)
		return (rra(a));
	else if (ft_strncmp(line, "rrb") == 1)
		return (rrb(b));
	else if (ft_strncmp(line, "rrr") == 1)
		return (rrr(a, b));
	return (0);
}

void	ft_data_entry(t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{	
		if (ft_check_line(a, b, line) == 0)
		{
			free(line);
			ft_stack_free(a);
			ft_stack_free(b);
			error(5);
		}
		free(line);
	}
	free(line);
}

//Запускаем программу
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		stack_init_a_str(&a, argc - 1, argv);
	else
		stack_init_a(&a, argc - 1, argv);
	stack_init_b(&b, a.count_max);
	if (stack_duplicate(a) == 0)
	{
		ft_stack_free(&a);
		ft_stack_free(&b);
		error (3);
	}
	ft_data_entry(&a, &b);
	if (stack_check_sort(a) == 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	ft_stack_free(&a);
	ft_stack_free(&b);
	return (0);
}

//Распечатывает стек
// void 	stack_print(t_stack a, t_stack b)
// {
// 	int i;
// 	if (a.count > b.count)
// 		i = a.count - 1;
// 	else
// 		i = b.count - 1;
// 	printf("_____________________________________________\n");
// 	while (i >= 0)
// 	{
// 		printf("%-11d |", a.value[i]);
// 		printf("%11d\n", b.value[i]);
// 		i--;
// 	}
// 	printf("_____________________________________________\n");
// 	printf("%10c(%d)", a.name, a.count);
// 	printf("%20c(%d)\n", b.name, b.count);
// }
