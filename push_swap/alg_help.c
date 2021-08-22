#include "push_swap.h"

static void	ft_alg_help_help(t_stack *a, t_stack *b, int *q_1, int *q_2);
static int	ft_shift_help(t_stack *b, int q);

// Некоторые операции движения стека А и Б можно объединить,
// Найдём самый лучший вариант
int	ft_alg_help(t_stack *a, t_stack *b, int oper_ra, int oper_rra)
{
	int	qual;
	int	q_1;
	int	q_2;

	qual = 0;
	ft_alg_help_help(a, b, &q_1, &q_2);
	if (q_1 <= q_2)
	{
		if (oper_ra < oper_rra)
			qual += ft_cycle_rr(a, b, &oper_ra, &q_1);
		else
			qual += ft_cycle_rra_rb(a, b, &oper_rra, &q_1);
	}
	else
	{
		if (oper_ra < oper_rra)
			qual += ft_cycle_ra_rrb(a, b, &oper_ra, &q_2);
		else
			qual += ft_cycle_rrr(a, b, &oper_rra, &q_2);
	}
	return (qual);
}

// Некоторые операции движения стека А и Б можно объединить,
// Найдём самый лучший вариант
static void	ft_alg_help_help(t_stack *a, t_stack *b, int *q_1, int *q_2)
{
	t_stack	b_copy;
	int		max_ind;
	int		min_ind;

	stack_init_b(&b_copy, b->count_max);
	max_ind = ft_stack_search_max(*b);
	min_ind = ft_stack_search_min(*b);
	if (a->ind > max_ind || a->ind < min_ind)
	{
		ft_stack_copy(b, &b_copy);
		*q_1 = ft_alg_help_rb_kray(&b_copy);
		ft_stack_copy(b, &b_copy);
		*q_2 = ft_alg_help_rrb_kray(&b_copy);
	}
	else
	{
		ft_stack_copy(b, &b_copy);
		*q_1 = ft_alg_help_rb(&b_copy, a->ind);
		ft_stack_copy(b, &b_copy);
		*q_2 = ft_alg_help_rrb(&b_copy, a->ind);
	}
	ft_stack_free(&b_copy);
}

// После того, как все элементы в стеке Б, они будет отсортированы,
// Но не факт, что самый большой элемент вверху, помсетим его туда
int	ft_shift(t_stack *b)
{
	int	qual;
	int	max_ind;
	int	max_pos;
	int	q;

	qual = 0;
	max_ind = ft_stack_search_max(*b);
	max_pos = ft_pos_ind(*b, max_ind);
	if ((max_ind - max_pos) < (max_pos + 1))
	{
		q = max_ind - max_pos;
		while (q > 0)
		{
			if (b->mode == 1)
				ft_putstr("rb\n");
			qual += rb(b);
			q--;
		}
	}
	else
	{
		q = max_pos + 1;
		qual += ft_shift_help(b, q);
	}
	return (qual);
}

// Продолжение логики ft_shift
static int	ft_shift_help(t_stack *b, int q)
{
	int	qual;

	qual = 0;
	while (q > 0)
	{
		if (b->mode == 1)
			ft_putstr("rrb\n");
		qual += rrb(b);
		q--;
	}
	return (qual);
}

// Когда элементы в стеке Б находятся в нужном порядке, переносим их в стек А
// Так же можно после разбиения стека попробовать сначала добавлять в 
// стек Б не часть, где элементы с минимальными индексами, а с максимальными
// и сравнить, что лучше
// А можно вообще рассмотреть все перестановки добавление частей в стек,
// только без оптимизации текущего кода для 500 элементов вычисления будут
// занимать не 3 секунды, а 300
int	ft_moving(t_stack *a, t_stack *b)
{
	int	qual;

	qual = 0;
	while (b->count > 0)
	{
		if (a->mode == 1)
			ft_putstr("pa\n");
		qual += pa(a, b);
	}
	return (qual);
}
