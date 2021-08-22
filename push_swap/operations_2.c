#include "push_swap.h"

//сдвиньте все элементы стека а на 1. 
//Первый элемент становится последним
int	ra(t_stack *a)
{
	int	t_value;
	int	t_index;
	int	i;

	if (a->count > 1)
	{
		t_value = a->value[a->count - 1];
		t_index = a->index[a->count - 1];
		i = a->count - 1;
		while (i > 0)
		{
			a->value[i] = a->value[i - 1];
			a->index[i] = a->index[i - 1];
			i--;
		}
		a->value[0] = t_value;
		a->index[0] = t_index;
	}
	return (1);
}

// сдвиньте все элементы стека b на 1. 
//Первый элемент становится последним
int	rb(t_stack *b)
{
	int	t_value;
	int	t_index;
	int	i;

	if (b->count > 1)
	{
		t_value = b->value[b->count - 1];
		t_index = b->index[b->count - 1];
		i = b->count - 1;
		while (i > 0)
		{
			b->value[i] = b->value[i - 1];
			b->index[i] = b->index[i - 1];
			i--;
		}
		b->value[0] = t_value;
		b->index[0] = t_index;
	}
	return (1);
}

// ra и rb одновременно
int	rr(t_stack *a, t_stack *b)
{
	if (a->count > 1)
		ra(a);
	if (b->count > 1)
		rb(b);
	return (1);
}

// сдвиньте вниз все элементы стека а на 1. 
//Последний элемент становится первым.
int	rra(t_stack *a)
{
	int	t_value;
	int	t_index;
	int	i;

	if (a->count > 1)
	{
		t_value = a->value[0];
		t_index = a->index[0];
		i = 0;
		while (i < (a->count - 1))
		{
			a->value[i] = a->value[i + 1];
			a->index[i] = a->index[i + 1];
			a->index[i] = a->index[i + 1];
			i++;
		}
		a->value[a->count - 1] = t_value;
		a->index[a->count - 1] = t_index;
	}
	return (1);
}

// сдвиньте вниз все элементы стека b на 1. 
//Последний элемент становится первым.
int	rrb(t_stack *b)
{
	int	t_value;
	int	t_index;
	int	i;

	if (b->count > 1)
	{
		t_value = b->value[0];
		t_index = b->index[0];
		i = 0;
		while (i < (b->count - 1))
		{
			b->value[i] = b->value[i + 1];
			b->index[i] = b->index[i + 1];
			b->index[i] = b->index[i + 1];
			i++;
		}
		b->value[b->count - 1] = t_value;
		b->index[b->count - 1] = t_index;
	}
	return (1);
}
