#include "checker.h"

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
