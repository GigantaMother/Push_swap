NAME	=	checker

HEADER	=   checker.h

SRC		=	check.c			get_next_line_utils.c	get_next_line.c\
			init.c			main.c 					operations_1.c\
			operations_2.c	operations_3.c			utilities.c

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