#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_number(char *str)
{
	int	i;

	i = 0;
	if ((ft_strlen(str) == 1) && (str[0] == '-'))
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_stack_search_max(t_stack a)
{
	int	i;
	int	max;

	i = 0;
	max = a.index[0];
	while (i < a.count)
	{
		if (a.index[i] > max)
		{
			max = a.index[i];
		}
		i++;
	}
	return (max);
}

int	ft_stack_search_min(t_stack a)
{
	int	i;
	int	min;

	i = 0;
	min = a.index[0];
	while (i < a.count)
	{
		if (a.index[i] < min)
		{
			min = a.index[i];
		}
		i++;
	}
	return (min);
}
