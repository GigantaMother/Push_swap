#include "checker.h"

// rra и rrb одновременно
int	rrr(t_stack *a, t_stack *b)
{
	if (a->count > 1)
		rra(a);
	if (a->count > 1)
		rrb(b);
	return (1);
}

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
