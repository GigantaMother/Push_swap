#include "push_swap.h"

static int	ft_alg_up(t_stack *a, int start, int end, int *i);
static int	ft_alg_down(t_stack *a, int start, int end, int *j);
static int	ft_alg_log_1(t_stack *a, t_stack *b, int *i, int *j);

// Основнйо алгоритм поиска нужных элементов
// ищем элемент для индекс которого, будет находиться
// в нужнйо части разбиения
// Надо найти такой элемент, что бы он оказался в вверху стека
// за минимальное кол-во операций
int	ft_alg(t_stack *a, t_stack *b, int start, int end)
{
	int	qual;
	int	i;
	int	j;
	int	log;

	qual = 0;
	log = 0;
	while (42)
	{
		log = 0;
		log = ft_alg_up(a, start, end, &i);
		a->oper_ra = a->count - i - 1;
		log = ft_alg_down(a, start, end, &j);
		a->oper_rra = j + 1;
		if (log == 1)
			qual += ft_alg_log_1(a, b, &i, &j);
		else
			break ;
	}
	return (qual);
}

// Ищем такой элемент сверху стека
static int	ft_alg_up(t_stack *a, int start, int end, int *i)
{
	*i = a->count - 1;
	while (*i >= 0)
	{
		if (a->index[*i] >= start && a->index[*i] <= end)
			return (1);
		*i = *i - 1;
	}
	return (0);
}

// Ищем такой элемент снизу стека
static int	ft_alg_down(t_stack *a, int start, int end, int *j)
{
	*j = 0;
	while (*j < a->count)
	{
		if (a->index[*j] >= start && a->index[*j] <= end)
			return (1);
		*j = *j + 1;
	}
	return (0);
}

// Если такой элемнт найден, то считаем нужное кол-во операций для его
// перемещения в нужнео место
static int	ft_alg_log_1(t_stack *a, t_stack *b, int *i, int *j)
{
	int	qual;

	qual = 0;
	if (b->count < 2)
	{	
		if (a->oper_ra < a->oper_rra)
			qual += ft_cycle_ra(a, &a->oper_ra);
		else
			qual += ft_cycle_rra(a, &a->oper_rra);
	}
	else
	{
		if (a->oper_ra < a->oper_rra)
			a->ind = a->index[*i];
		else
			a->ind = a->index[*j];
		qual += ft_alg_help(a, b, a->oper_ra, a->oper_rra);
	}
	if (a->mode == 1)
		ft_putstr("pb\n");
	qual += pb(a, b);
	return (qual);
}
