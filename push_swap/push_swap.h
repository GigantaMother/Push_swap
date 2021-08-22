#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
//# include <stdio.h>

typedef struct s_stack
{
	int		*value;
	int		*index;
	int		count_max;
	int		count;
	int		mode;
	int		ind;
	int		oper_ra;
	int		oper_rra;
	int		max_part;
	int		min_part;
	int		rational_part;
	int		oper_min;
}				t_stack;

void	ft_number_str(char *str, int *i, int *value);

//main.c (3)
void	ft_number_str(char *str, int *i, int *value);

//init.c (5)
void	stack_init_a_str(t_stack *a, int count, char **argv);
void	stack_init_a(t_stack *a, int count, char **argv);
void	stack_init_b(t_stack *b, int count);
void	ft_stack_copy(t_stack *original, t_stack *copy);
void	ft_stack_free(t_stack *stack);

//alg_start.c (4)
int		ft_alg(t_stack *a, t_stack *b, int start, int end);

//alg_help.c (4)
int		ft_alg_help(t_stack *a, t_stack *b, int oper_ra, int oper_rra);
int		ft_shift(t_stack *b);
int		ft_moving(t_stack *a, t_stack *b);

//search_part.c (5)
void	ft_option_part(int count, int *max_part, int *min_part);
void	ft_best_part(int *oper_min, int *rational_part, int QUAL, int min_part);
int		ft_part_search_end(int y, int min_part, int count);
void	ft_search_best_part(t_stack *a, t_stack *b);
int		ft_search_best_part_help(t_stack *a, t_stack *b, \
t_stack *a_copy, t_stack *b_copy);

//check_stek.c (5)
int		stack_check_sort(t_stack a);
int		stack_check_sort_reverse(t_stack stack);
void	ft_sort_reverse(t_stack *a, t_stack *b);

//alg_small_element.c(5)
void	ft_alg_3_num(t_stack *a);
void	ft_alg_4_num(t_stack *a, t_stack *b);
void	ft_funk_5_num(t_stack *a, t_stack *b);

//index.c (3)
void	ft_index(t_stack *a);

//count_shift.c (5)
int		ft_pos_ind(t_stack a, int ind);
int		ft_alg_help_rb_kray(t_stack *b);
int		ft_alg_help_rrb_kray(t_stack *b);
int		ft_alg_help_rb(t_stack *b, int ind);
int		ft_alg_help_rrb(t_stack *b, int ind);

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

//operations_3.c (5)
int		rrr(t_stack *a, t_stack *b);
int		ft_cycle_ra(t_stack *a, int *i);
int		ft_cycle_rra(t_stack *a, int *i);
int		ft_cycle_rb(t_stack *b, int *i);
int		ft_cycle_rrb(t_stack *b, int *i);

//operations_4.c (4)
int		ft_cycle_rr(t_stack *a, t_stack *b, int *i, int *j);
int		ft_cycle_rrr(t_stack *a, t_stack *b, int *i, int *j);
int		ft_cycle_rra_rb(t_stack *a, t_stack *b, int *i, int *j);
int		ft_cycle_ra_rrb(t_stack *a, t_stack *b, int *i, int *j);

//error.c (2)
int		error(int e);
int		stack_search_duplicate(t_stack a);

//utilities_1.c (5)
int		ft_strlen(char *str);
int		max(int a, int b);
int		min(int a, int b);
void	swap(int *a, int *b);
int		ft_atoi(const char *str, int *value);

//utilities_2.c (5)
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_number(char *str);
int		ft_stack_search_max(t_stack a);
int		ft_stack_search_min(t_stack a);

#endif