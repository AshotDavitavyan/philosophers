NAME	=	philo

CC		=	gcc
SRC_DIR	=	src
OBJ_DIR =	obj
CFLAGS	=	-Wall -Wextra -Werror -g
RM		=	rm -f

SRCS	=	$(wildcard $(SRC_DIR)/*.c)

LIBFT_DIR = ./libft/

OBJS	=	$(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFT_DIR) all 
			cc -o $(NAME) $(OBJS) -g $(CFLAGS) $(LIBS) -L$(LIBFT_DIR) -lft
.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJS)
			make -C $(LIBFT_DIR) clean
			
fclean:		clean
			@$(RM) $(NAME)
			make -C $(LIBFT_DIR) fclean

re:			fclean all
			make -C $(LIBFT_DIR) re

.PHONY:		all clean fclean re
