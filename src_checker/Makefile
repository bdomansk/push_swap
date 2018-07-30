# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 11:49:05 by bdomansk          #+#    #+#              #
#    Updated: 2018/04/23 11:49:07 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../checker
LIB = ../libft/libft.a
LIBDIR = ../libft
FLAGS = -Wall -Wextra -Werror
CHECKER_SRC =  ft_validate.c ft_free_arr.c ft_check_duplicate.c ft_swap.c \
			ft_check_commands.c ft_putstack.c ft_free_stack.c ft_error.c \
			ft_push.c ft_rotate.c ft_reverse_rotate.c ft_check_ps_flags.c \
			main.c ft_ps_status.c ft_check_sort.c

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
HEADER = ../push_swap.h
DEL = /bin/rm -f

.PHONY : all clean n fclean re

all : $(NAME)

$(NAME) : $(LIB) $(CHECKER_OBJ) 
	@echo "Compiling checker"
	@gcc $(FLAGS) $(CHECKER_OBJ) -o $(NAME) $(LIB)

$(CHECKER_OBJ): $(CHECKER_SRC)
	@echo "Checker objects creating"
	@gcc $(FLAGS) -c $(CHECKER_SRC)

$(LIB) :
	@make -C $(LIBDIR)

clean:
	@$(DEL) $(CHECKER_OBJ)

n :
	@norminette $(CHECKER_SRC)

fclean:
	@$(DEL) $(CHECKER_OBJ)
	@$(DEL) $(NAME)
	
re: fclean all 