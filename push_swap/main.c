#include "push_swap.h"

//void 	stack_print(t_stack a, t_stack b);
static int	alg_start(t_stack *a, t_stack *b);
static void	ft_final(t_stack *a, t_stack *b);
static void	ft_final(t_stack *a, t_stack *b);

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
	if (alg_start(&a, &b) != 1)
	{
		ft_index(&a);
		ft_search_best_part(&a, &b);
		a.mode = 1;
		b.mode = 1;
		ft_final(&a, &b);
		ft_stack_free(&a);
		ft_stack_free(&b);
	}
	return (0);
}
//stack_print(a, b);

// Проверяет варианты, которые не вписываются в общий алгоритм
static int	alg_start(t_stack *a, t_stack *b)
{
	if (stack_search_duplicate(*a) == 0)
	{	
		ft_stack_free(a);
		ft_stack_free(b);
		error (3);
	}
	if (stack_check_sort(*a) == 1)
		return (1);
	if (stack_check_sort_reverse(*a) == 1)
	{
		ft_sort_reverse(a, b);
		return (1);
	}
	else if (a->count >=3 && a->count <= 5)
	{
		ft_index(a);
		if (a->count == 3)
			ft_alg_3_num(a);
		if (a->count == 4)
			ft_alg_4_num(a, b);
		if (a->count == 5)
			ft_funk_5_num(a, b);
		return (1);
	}
	return (0);
}

// Когда мы нашли нужное разбиение, то выполним его
static void	ft_final(t_stack *a, t_stack *b)
{
	int	y;
	int	start;
	int	end;
	int	all;

	y = 0;
	start = 0;
	all = a->count;
	end = (a->count / a->rational_part) * (y + 1) - 1;
	while (y <= a->rational_part)
	{
		ft_alg(a, b, start, end);
		start = end + 1;
		if ((y + 1) == a->rational_part)
			end = all;
		else
			end = (all / a->rational_part) * (y + 1) - 1;
		y++;
	}
	ft_shift(b);
	ft_moving(a, b);
}

//Распечатывает стек
// void 	stack_print(t_stack a, t_stack b)
// {
// 	int i;

// 	i = max(a.count, b.count) - 1;
// 	printf("_____________________________________________\n");
// 	while (i >= 0)
// 	{
// 		printf("%-11d(%4d) |", a.value[i], a.index[i]);
// 		printf("%11d(%4d)\n", b.value[i], b.index[i]);
// 		i--;
// 	}
// 	printf("_____________________________________________\n");
// 	printf("%10c(%d)", 'a', a.count);
// 	printf("%20c(%d)\n", 'b', b.count);
// }
