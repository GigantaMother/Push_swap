#include "push_swap.h"

// Ошибки, которые могут возникнуть
int	error(int e)
{
	ft_putstr("Error\n");
	if (e == 1)
		ft_putstr("Ошибка малока\n");
	else if (e == 2)
		ft_putstr("Один из аргументов не число\n");
	else if (e == 3)
		ft_putstr ("Есть дубликаты\n");
	else if (e == 4)
		ft_putstr ("Число выходит за пределы int\n");
	else
		ft_putstr("Неизвестная ошибка\n");
	exit (0);
}

// Проверяет, нет ли повторяющихся элементов
int	stack_search_duplicate(t_stack a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a.count_max - 1)
	{
		j = i + 1;
		while (j < a.count_max)
		{
			if (a.value[i] == a.value[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Очистка памяти стека
void	ft_stack_free(t_stack *stack)
{
	free(stack->value);
	free(stack->index);
}

//Обработок чисел, когда числа находятся в одной строке
void	ft_number_str(char *str, int *i, int *value)
{
	long long int	num;
	int				zn;

	zn = 0;
	num = 0;
	if (str[*i] == '-')
	{
		zn = 1;
		*i = *i + 1;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = num * 10 + str[*i] - 48;
		if (((num > 2147483647) && (zn == 0)) || \
		((num > 2147483648) && (zn == 1)))
			error (4);
		if (str[*i] < '0' || str[*i] > '9')
			error(2);
		*i = *i + 1;
	}
	if (zn == 1 && num == 0)
		error(2);
	if (zn == 1)
		num = -num;
	*value = num;
}
