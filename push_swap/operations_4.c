#include "push_swap.h"

//rr определённое кол-во раз
int	ft_cycle_rr(t_stack *a, t_stack *b, int *i, int *j)
{
	int	q;

	q = 0;
	while (*i > 0 && *j > 0)
	{
		if (a->mode == 1)
			ft_putstr("rr\n");
		q += rr(a, b);
		*i = *i - 1;
		*j = *j - 1;
	}
	q += ft_cycle_ra(a, i);
	q += ft_cycle_rb(b, j);
	return (q);
}

//rrr определённое кол-во раз
int	ft_cycle_rrr(t_stack *a, t_stack *b, int *i, int *j)
{
	int	q;

	q = 0;
	while (*i > 0 && *j > 0)
	{
		if (a->mode == 1)
			ft_putstr("rrr\n");
		q += rrr(a, b);
		*i = *i - 1;
		*j = *j - 1;
	}
	q += ft_cycle_rra(a, i);
	q += ft_cycle_rrb(b, j);
	return (q);
}

//rra и rb определённое кол-во раз
int	ft_cycle_rra_rb(t_stack *a, t_stack *b, int *i, int *j)
{
	int	q;

	q = 0;
	q += ft_cycle_rra(a, i);
	q += ft_cycle_rb(b, j);
	return (q);
}

//ra и rrb определённое кол-во раз
int	ft_cycle_ra_rrb(t_stack *a, t_stack *b, int *i, int *j)
{
	int	q;

	q = 0;
	q += ft_cycle_ra(a, i);
	q += ft_cycle_rrb(b, j);
	return (q);
}
