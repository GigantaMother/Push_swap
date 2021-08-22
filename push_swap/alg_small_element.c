#include "push_swap.h"

static	void	ft_funk_3_help(t_stack *a);
static void	ft_funk_5_help(t_stack *a, int pos);

// Алгоритм для 3 элементов
void	ft_alg_3_num(t_stack *a)
{
	if (a->value[2] > a->value[1] && a->value[2] < a->value[0])
	{
		sa(a);
		ft_putstr("sa\n");
	}
	else if (a->value[2] < a->value[1] && a->value[2] > a->value[0])
	{
		rra(a);
		ft_putstr("rra\n");
	}
	else if (a->value[2] < a->value[1] && a->value[1] > a->value[0])
	{
		sa(a);
		ft_putstr("sa\n");
		ra(a);
		ft_putstr("ra\n");
	}
	else
		ft_funk_3_help(a);
}

// Алгоритм для 4 элементов
void	ft_alg_4_num(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	min = ft_stack_search_min(*a);
	pos = ft_pos_ind(*a, min);
	if (pos == 2 || pos == 1)
	{
		ra(a);
		ft_putstr("ra\n");
	}
	if (pos == 1)
	{
		ra(a);
		ft_putstr("ra\n");
	}
	else if (pos == 0)
	{
		rra(a);
		ft_putstr("rra\n");
	}
	pb(a, b);
	ft_putstr("pb\n");
	ft_alg_3_num(a);
	ft_putstr("pa\n");
	pa(a, b);
}

// Алгоритм для 5 элементов
void	ft_funk_5_num(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	min = ft_stack_search_min(*a);
	pos = ft_pos_ind(*a, min);
	ft_funk_5_help(a, pos);
	pb(a, b);
	ft_putstr("pb\n");
	ft_alg_4_num(a, b);
	ft_putstr("pa\n");
	pa(a, b);
}

// Алгоритм для 3 элементов (продолжение логики алгоритма)
static	void	ft_funk_3_help(t_stack *a)
{
	if (a->value[2] > a->value[1] && a->value[1] < a->value[0])
	{
		ra(a);
		ft_putstr("ra\n");
	}
	else if (a->value[2] > a->value[1] && a->value[1] > a->value[0])
	{
		sa(a);
		ft_putstr("sa\n");
		rra(a);
		ft_putstr("rra\n");
	}
}

// Алгоритм для 5 элементов (продолжение логики алгоритма)
static void	ft_funk_5_help(t_stack *a, int pos)
{
	if (pos == 3)
	{
		ra(a);
		ft_putstr("ra\n");
	}
	else if (pos == 2)
	{
		ra(a);
		ft_putstr("ra\n");
		ra(a);
		ft_putstr("ra\n");
	}
	else if (pos == 1)
	{
		rra(a);
		ft_putstr("rra\n");
		rra(a);
		ft_putstr("rra\n");
	}
	else if (pos == 0)
	{
		rra(a);
		ft_putstr("rra\n");
	}
}
