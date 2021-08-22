#include "checker.h"

// поменяйте местами первые 2 элемента в верхней части стека a. 
// Ничего не делай если естьесть только один элемент или его нет
int	sa(t_stack *a)
{
	if (a->count > 1)
		swap(&a->value[a->count - 1], &a->value[a->count - 2]);
	return (1);
}

//поменяйте местами первые 2 элемента в верхней части стека b. 
//Ничего не делай если естьесть только один элемент или его нет
int	sb(t_stack *b)
{
	if (b->count > 1)
		swap(&b->value[b->count - 1], &b->value[b->count - 2]);
	return (1);
}

// sa и sb одновременно
int	ss(t_stack *a, t_stack *b)
{
	if (a->count > 1)
		sa(a);
	if (b->count > 1)
		sb(b);
	return (1);
}

// возьмите первый элемент в верхней части b и поместите его в верхнюю часть a.
//Ничего не делайте, если b пуст
int	pa(t_stack *a, t_stack *b)
{
	if (b->count != 0)
	{
		a->value[a->count] = b->value[b->count - 1];
		b->value[b->count - 1] = -1;
		a->count++;
		b->count--;
	}
	return (1);
}

//возьмите первый элемент в верхней части a и поместите его в верхнюю часть b.
//Ничего не делайте, если a пуст
int	pb(t_stack *a, t_stack *b)
{
	if (a->count != 0)
	{
		b->value[b->count] = a->value[a->count - 1];
		a->value[a->count - 1] = -1;
		b->count++;
		a->count--;
	}
	return (1);
}
