NAME	=	push_swap

HEADER	=   push_swap.h

SRC		=	alg_help.c		alg_small_element.c		alg_start.c\
			check_stek.c	count_shift.c			utilities_1.c\
			error.c			index.c					init.c\
			main.c 			operations_1.c			operations_2.c\
			operations_3.c	operations_4.c			search_part.c\
			utilities_2.c

FLAGS	=	-Wall -Wextra -Werror

OBJ		=	$(patsubst %.c, %.o, $(SRC))

all		: $(NAME)

$(NAME)	:	$(SRC) $(HEADER)
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re