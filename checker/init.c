#include "checker.h"

// Когда параметры являются одним аргументом,
// подсчитаем сколько чисел содержится в строке
void	stack_init_a_str_count(t_stack *a, char **argv)
{
	int	i;
	int	log;

	a->count_max = 0;
	i = 0;
	log = 0;
	while (argv[1][i])
	{
		if ((argv[1][i] < '0' || argv[1][i] > '9') && argv[1][i] != ' ' \
		&& argv[1][i] != '\t' && argv[1][i] != '\n' && argv[1][i] != '-')
			error(2);
		if (argv[1][i] != ' ' && argv[1][i] != '\t' \
		&& argv[1][i] != '\n' && log == 0)
		{
			a->count_max++;
			log = 1;
		}
		else if (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\n')
			log = 0;
		i++;
	}
}

// Выделяем память и задаём начальные параметры стека а
// Случай, когда аргументы являются строкой
void	stack_init_a_str(t_stack *a, int count, char **argv)
{
	int	j;

	j = 0;
	if (ft_strlen(argv[1]) == 0)
		exit (0);
	stack_init_a_str_count(a, argv);
	a->count = a->count_max;
	a->mode = 0;
	a->value = malloc(sizeof(a->value) * a->count_max);
	if (a->value == NULL)
		error(1);
	count = a->count_max - 1;
	while (count >= 0)
	{
		while (argv[1][j] == ' ' || argv[1][j] == '\t' || argv[1][j] == '\n')
			j++;
		ft_number_str(argv[1], &j, &a->value[count]);
		count--;
	}
}

// Выделяем память и задаём начальные параметры стека а
void	stack_init_a(t_stack *a, int count, char **argv)
{
	int	i;

	i = 0;
	a->count_max = count;
	a->count = count;
	a->name = 'a';
	a->mode = 0;
	a->value = malloc(sizeof(a->value) * count);
	if (a->value == NULL)
		error(1);
	count--;
	while (count >= 0)
	{
		if (ft_number(argv[count + 1]) == 0)
			error(2);
		if (ft_atoi(argv[count + 1], &a->value[i]) == 0)
			error(4);
		count--;
		i++;
	}
}

// Выделяем память и задаём начальные параметры стека б
void	stack_init_b(t_stack *b, int count)
{
	int	i;

	i = 0;
	b->count_max = count;
	b->count = 0;
	b->name = 'b';
	b->mode = 0;
	b->value = malloc(sizeof(b->value) * count);
	if (b->value == NULL)
		error(1);
	count--;
	while (count >= 0)
	{
		b->value[i] = -1;
		count--;
		i++;
	}
}

// Очистка памяти стека
void	ft_stack_free(t_stack *stack)
{
	free(stack->value);
}
