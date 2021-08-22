#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_atoi(const char *str, int *value)
{
	long long int	num;
	int				zn;
	int				i;

	zn = 0;
	num = 0;
	i = 0;
	if (str[i] == '-')
	{
		zn = 1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + str[i] - 48;
		if ((num > 2147483647) && (zn == 0))
			return (0);
		if ((num > 2147483648) && (zn == 1))
			return (0);
		i++;
	}
	if (zn == 1)
		num = num * (-1);
	*value = num;
	return (1);
}
