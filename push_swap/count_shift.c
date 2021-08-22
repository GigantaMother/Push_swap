#include "push_swap.h"

// Ищет позицию элемента с нужным индексом
int	ft_pos_ind(t_stack a, int ind)
{
	int	i;

	i = 0;
	while (i < a.count)
	{
		if (a.index[i] == ind)
			return (i);
		i++;
	}
	return (-1);
}

// Подсчитывает сколько операция rb надо сделать, что бы
// нужный нам элемент оказался в правильнмо месте
// случай, когда индекс элемента, который мы хотим перенести
// имеет имеет больше или меньше, чем все остальные элементы
int	ft_alg_help_rb_kray(t_stack *b)
{
	int	q;
	int	min_ind;

	q = 0;
	min_ind = ft_stack_search_max(*b);
	while (42)
	{
		if (b->index[b->count - 1] == min_ind)
			break ;
		else
		{
			rb(b);
			q++;
		}
	}
	return (q);
}

// Аналогично, для операций rrb
int	ft_alg_help_rrb_kray(t_stack *b)
{
	int	q;
	int	min_ind;

	q = 0;
	min_ind = ft_stack_search_max(*b);
	while (42)
	{
		if (b->index[b->count - 1] == min_ind)
			break ;
		else
		{
			rrb(b);
			q++;
		}
	}
	return (q);
}

// Аналогично, только рассматривается обший случай,
// Индекс элемента меньше хотя бы одного элемента из другого стека и
// Индекс элемента больше хотя бы одного элемента из другого стека и 
int	ft_alg_help_rb(t_stack *b, int ind)
{
	int	q;

	q = 0;
	while (42)
	{
		if ((b->index[b->count - 1] < ind) && (b->index[0] > ind))
		{
			break ;
		}
		else
		{
			rb(b);
			q++;
		}
	}
	return (q);
}

// Аналогично, для операций rrb
int	ft_alg_help_rrb(t_stack *b, int ind)
{
	int	q;

	q = 0;
	while (42)
	{
		if ((b->index[b->count - 1] < ind) && (b->index[0] > ind))
		{
			break ;
		}
		else
		{
			rrb(b);
			q++;
		}
	}
	return (q);
}
