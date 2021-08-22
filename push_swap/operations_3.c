#include "push_swap.h"

// rra и rrb одновременно
int	rrr(t_stack *a, t_stack *b)
{
	if (a->count > 1)
		rra(a);
	if (a->count > 1)
		rrb(b);
	return (1);
}

// ra определённое кол-во раз
int	ft_cycle_ra(t_stack *a, int *i)
{
	int	q;

	q = 0;
	while (*i > 0)
	{
		if (a->mode == 1)
			ft_putstr("ra\n");
		q += ra(a);
		*i = *i - 1;
	}
	return (q);
}

// rra определённое кол-во раз
int	ft_cycle_rra(t_stack *a, int *i)
{
	int	q;

	q = 0;
	while (*i > 0)
	{
		if (a->mode == 1)
			ft_putstr("rra\n");
		q += rra(a);
		*i = *i - 1;
	}
	return (q);
}

// rb определённое кол-во раз
int	ft_cycle_rb(t_stack *b, int *i)
{
	int	q;

	q = 0;
	while (*i > 0)
	{
		if (b->mode == 1)
			ft_putstr("rb\n");
		q += rb(b);
		*i = *i - 1;
	}
	return (q);
}

// rrb определённое кол-во раз
int	ft_cycle_rrb(t_stack *b, int *i)
{
	int	q;

	q = 0;
	while (*i > 0)
	{
		if (b->mode == 1)
			ft_putstr("rrb\n");
		q += rrb(b);
		*i = *i - 1;
	}
	return (q);
}
