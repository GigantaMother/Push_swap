#include "push_swap.h"

static int	ft_index_start(t_stack *a);
static int	ft_index_search(t_stack *a, int mark, int min_pred);

//Индексирует элементы начиная с 0
void	ft_index(t_stack *a)
{
	int	min_pred;
	int	mark;
	int	c;

	min_pred = ft_index_start(a);
	mark = 1;
	c = 0;
	while (c < (a->count - 1))
	{
		min_pred = ft_index_search(a, mark, min_pred);
		mark++;
		c++;
	}
}

// Ставит 1 индекс
static int	ft_index_start(t_stack *a)
{
	int	min;
	int	pos;
	int	i;

	min = a->value[0];
	pos = 0;
	i = 1;
	while (i < a->count)
	{
		if (a->value[i] < min)
		{
			min = a->value[i];
			pos = i;
		}
		i++;
	}
	a->index[pos] = 0;
	return (min);
}

// Ищет следующий индекс
static int	ft_index_search(t_stack *a, int mark, int min_pred)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = 2147483647;
	while (i < a->count)
	{
		if ((a->value[i] <= min) && (a->value[i] > min_pred))
		{
			min = a->value[i];
			pos = i;
		}
		i++;
	}
	a->index[pos] = mark;
	return (min);
}
