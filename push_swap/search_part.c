#include "push_swap.h"

// Определяет на сколько частей лучше всег оподелить стек для сортировки
void	ft_option_part(int count, int *max_part, int *min_part)
{
	if (count < 20)
	{
		*max_part = 2;
		*min_part = 1;
	}
	else if (count < 500)
	{
		*max_part = 11;
		*min_part = 1;
	}
	else
	{
		*max_part = 31;
		*min_part = 10;
	}
}

// Выбирает лучшую часть, ориентируется на кол-во операций
void	ft_best_part(int *oper_min, int *rational_part, int qual, int min_part)
{
	if (*oper_min == -1)
	{
		*oper_min = qual;
		*rational_part = min_part;
	}
	else if (*oper_min > qual)
	{
		*oper_min = qual;
		*rational_part = min_part;
	}
}

// При деление стека на части, важно,
// что бы все элементы находились только в одной части
// При некоторых вариантах деления,
// в конце могут остаться не использованные элементы
// Присвоим их к последней части
int 	ft_part_search_end(int y, int min_part, int count)
{
	int	end;

	if ((y + 1) == min_part)
		end = count;
	else
		end = (count / min_part) * (y + 1) - 1;
	return (end);
}

//Пробуем разбить стек на разное кол-во частей
void	ft_search_best_part(t_stack *a, t_stack *b)
{
	t_stack	a_copy;
	t_stack	b_copy;
	int		qual;

	a->oper_min = -1;
	stack_init_b(&a_copy, a->count - 1);
	stack_init_b(&b_copy, a->count - 1);
	qual = 0;
	ft_option_part(a->count, &a->max_part, &a->min_part);
	while (a->min_part < a->max_part)
	{		
		ft_search_best_part_help(a, b, &a_copy, &b_copy);
		a->min_part++;
	}
	ft_stack_free(&a_copy);
	ft_stack_free(&b_copy);
}

//Для каждого разбиения, считаем кол-во операций
int	ft_search_best_part_help(t_stack *a, t_stack *b, \
t_stack *a_copy, t_stack *b_copy)
{
	int	y;
	int	qual;
	int	start;
	int	end;

	y = 0;
	qual = 0;
	start = 0;
	end = (a->count / a->min_part) * (y + 1) - 1;
	ft_stack_copy(a, a_copy);
	ft_stack_copy(b, b_copy);
	while (y <= a->min_part)
	{
		qual += ft_alg(a_copy, b_copy, start, end);
		start = end + 1;
		end = ft_part_search_end(y, a->min_part, a->count);
		y++;
	}
	qual += ft_shift(b_copy);
	qual += ft_moving(a_copy, b_copy);
	ft_best_part(&a->oper_min, &a->rational_part, qual, a->min_part);
	return (qual);
}
