#include "push_swap.h"

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
	a->ind = -1;
	a->value = malloc(sizeof(a->value) * a->count_max);
	if (a->value == NULL)
		error(1);
	a->index = malloc(sizeof(a->value) * a->count_max);
	if (a->index == NULL)
		error(1);
	count = a->count_max - 1;
	while (count >= 0)
	{
		while (argv[1][j] == ' ' || argv[1][j] == '\t' || argv[1][j] == '\n')
			j++;
		ft_number_str(argv[1], &j, &a->value[count]);
		a->index[count] = -1;
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
	a->mode = 0;
	a->ind = -1;
	a->value = malloc(sizeof(a->value) * count);
	if (a->value == NULL)
		error(1);
	a->index = malloc(sizeof(a->value) * count);
	if (a->index == NULL)
		error(1);
	count--;
	while (count >= 0)
	{
		if (ft_number(argv[count + 1]) == 0)
			error(2);
		if (ft_atoi(argv[count + 1], &a->value[i]) == 0)
			error(4);
		a->index[i] = -1;
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
	b->mode = 0;
	b->ind = -1;
	b->value = malloc(sizeof(b->value) * count);
	if (b->value == NULL)
		error(1);
	b->index = malloc(sizeof(b->value) * count);
	if (b->index == NULL)
		error(1);
	count--;
	while (count >= 0)
	{
		b->value[i] = -1;
		b->index[i] = -1;
		count--;
		i++;
	}
}

// Копирование стека
void 	ft_stack_copy(t_stack *original, t_stack *copy)
{
	int	i;

	i = 0;
	copy->count_max = original->count_max;
	copy->count = original->count;
	copy->ind = original->ind;
	copy->max_part = original->max_part;
	copy->min_part = original->min_part;
	copy->rational_part = original->rational_part;
	copy->oper_min = original->oper_min;
	while (i < original->count)
	{
		copy->value[i] = original->value[i];
		copy->index[i] = original->index[i];
		i++;
	}
}
