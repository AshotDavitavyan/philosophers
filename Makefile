NAME	=	philo
NAMEB	=	philo_bonus

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g #-fsanitize=thread
RM		=	rm -rf

SRC_DIR	=	src/
SRCB_DIR =	src_bonus/
OBJ_DIR =	obj/
OBJB_DIR =	objb/
LIBFT_DIR = ./libft/

SRCS	=	$(wildcard $(SRC_DIR)*.c)
OBJS 	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
SRCSB	=	$(wildcard $(SRCB_DIR)*.c)
OBJB	=	$(patsubst $(SRCB_DIR)%.c,$(OBJB_DIR)%.o,$(SRCSB))
all:	$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFT_DIR) all 
			cc -o $(NAME) $(OBJS) -g $(CFLAGS) $(LIBS) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(NAMEB)

$(NAMEB):	$(OBJB)
			make -C $(LIBFT_DIR) all
			cc -o $(NAMEB) $(OBJB) -g $(CFLAGS) $(LIBS) -L$(LIBFT_DIR) -lft

$(OBJB_DIR)%.o: $(SRCB_DIR)%.c
	@mkdir -p $(OBJB_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS) $(OBJ_DIR) $(OBJB) $(OBJB_DIR)
			make -C $(LIBFT_DIR) clean
			
fclean:		clean
			@$(RM) $(NAME) $(NAMEB)
			make -C $(LIBFT_DIR) fclean

re:			fclean all
			make -C $(LIBFT_DIR) re

.PHONY:		all clean fclean re
