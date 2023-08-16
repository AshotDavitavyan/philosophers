NAME	=	philo

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g #-fsanitize=thread
RM		=	rm -rf

SRC_DIR	=	src/
OBJ_DIR =	obj/
LIBFT_DIR = ./libft/

SRCS	=	$(wildcard $(SRC_DIR)*.c)
OBJS 	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS)
			echo $(SRCS)
			make -C $(LIBFT_DIR) all 
			cc -o $(NAME) $(OBJS) -g $(CFLAGS) $(LIBS) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS) $(OBJ_DIR)
			make -C $(LIBFT_DIR) clean
			
fclean:		clean
			@$(RM) $(NAME)
			make -C $(LIBFT_DIR) fclean

re:			fclean all
			make -C $(LIBFT_DIR) re

.PHONY:		all clean fclean re
