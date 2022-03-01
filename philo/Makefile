# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barcher <barcher@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 18:00:33 by barcher           #+#    #+#              #
#    Updated: 2021/07/04 17:42:39 by barcher          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRC_PATH	=	include/

SRC_FILES	=	ft_lstadd_back_phill.c\
				ft_lstlast_phill.c\
				ft_lstnew_phill.c\
				ft_lstiter_phill.c\
				ft_eating.c\
				ft_sleeping.c\
				ft_checkdead.c\
				ft_changedead.c\
				ft_lst_nu.c\
				ft_take_forks.c\
				ft_init_phil.c\
				ft_checksatiety.c\
				ft_time.c\
				ft_lm_time.c\
				print_status.c\
				ft_key_chain.c\
				ft_strlen.c\
				ft_strchr.c\
				ft_atoi.c\
				ft_check_input.c

PHIL		=	main.c

CC			=	gcc

FLAGS		= -Wall -Werror -Wextra

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o) 


SRC_OBJ		=	$(addprefix $(SRC_PATH),$(SRC_FILES:.c=.o))

PHIL_OBJ	=	$(PHIL:.c=.o)

all:		$(NAME)


$(NAME):	 $(PHIL_OBJ)  $(SRC_OBJ) include/philosophers.h
			gcc -pthread $(PHIL_OBJ)  $(SRC_OBJ) -o $(NAME)

clean:
			rm -rf  $(PHIL_OBJ) $(SRC_OBJ) 

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
			
.PHONY: 	all clean fclean re
