#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int		*value;
	int		count_max;
	int		count;
	char	name;
	int		mode;
}				t_stack;

//check.c (5)
int		stack_check_sort(t_stack a);
int		error(int e);
int		stack_duplicate(t_stack a);
int		ft_strncmp(char *str1, char *str2);
void	ft_number_str(char *str, int *i, int *value);

//init.c (3)
void	stack_init_a_str(t_stack *a, int count, char **argv);
void	stack_init_a(t_stack *a, int count, char **argv);
void	stack_init_b(t_stack *b, int count);
void	ft_stack_free(t_stack *stack);

//operations_1.c (5)
int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);
int		pa(t_stack *a, t_stack *b);
int		pb(t_stack *a, t_stack *b);

//operations_2.c (5)
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rr(t_stack *a, t_stack *b);
int		rra(t_stack *a);
int		rrb(t_stack *b);

//operations_3.c (2)
int		rrr(t_stack *a, t_stack *b);
void	swap(int *a, int *b);

//utilities_1.c (5)
int		ft_strlen(char *str);
int		ft_atoi(const char *str, int *value);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_number(char *str);

#endif
