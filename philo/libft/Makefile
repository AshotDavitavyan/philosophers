# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavitav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 10:58:31 by adavitav          #+#    #+#              #
#    Updated: 2023/02/05 10:10:16 by adavitav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_isalnum.c ft_isalpha.c ft_atoi.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_isprint.c ft_strlcat.c\
		ft_memmove.c ft_strlen.c ft_memcpy.c ft_strlcat.c ft_bzero.c ft_calloc.c\
		ft_strncmp.c ft_strlcpy.c ft_strnstr.c ft_memchr.c ft_memset.c ft_strchr.c\
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_strdup.c ft_putchar_fd.c\
		ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strjoin.c ft_substr.c\
		ft_strtrim.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_split.c\

SRCSB = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
	
	
OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o);

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean $(NAME)

bonus: 
	gcc $(FLAGS) -c $(SRCSB)
	ar rcs $(NAME) $(OBJSB)
