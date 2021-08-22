#include "push_swap.h"

static void	ft_sort_reverse_help(t_stack *a);
static void	ft_sort_reverse_base(t_stack *a, t_stack *b, \
int limit_1, int limit_2);

// Проверяет, отсортирвоан ли стек
int	stack_check_sort(t_stack a)
{
	int	i;

	i = 0;
	while (i < (a.count - 1))
	{
		if (a.value[i] < a.value[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// Проверяет, отсортирвоан ли стек в обратном порядке
int	stack_check_sort_reverse(t_stack stack)
{
	int	i;

	i = 0;
	while (i < (stack.count - 1))
	{
		if (stack.value[i] > stack.value[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// Сортирует стек, когда он отсортирован в обратном порядке
void	ft_sort_reverse(t_stack *a, t_stack *b)
{
	int	limit_1;
	int	limit_2;

	limit_1 = a->count - 1;
	limit_2 = a->count - 2;
	if (a->count == 2 || a->count == 3)
		ft_sort_reverse_help(a);
	else
		ft_sort_reverse_base(a, b, limit_1, limit_2);
}

// Алгоритм, когда стек отсортирован в обратном порядке для 2 или 3 элементов
static void	ft_sort_reverse_help(t_stack *a)
{
	if (a->count == 2)
	{
		sa(a);
		ft_putstr("sa\n");
	}
	else if (a->count == 3)
	{
		ra(a);
		ft_putstr("ra\n");
		sa(a);
		ft_putstr("sa\n");
	}
}

// Базовый алгорит сортировки, когда стек отсортирован в обратном порядке
static void	ft_sort_reverse_base(t_stack *a, t_stack *b, \
int limit_1, int limit_2)
{
	int	i;

	i = 0;
	ra(a);
	ft_putstr("ra\n");
	while (i < limit_1)
	{
		pb(a, b);
		ft_putstr("pb\n");
		i++;
	}
	i = 0;
	while (i < limit_2)
	{
		rrb(b);
		ft_putstr("rrb\n");
		pa(a, b);
		ft_putstr("pa\n");
		i++;
	}
	pa(a, b);
	ft_putstr("pa\n");
}
