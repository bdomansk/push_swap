# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 11:55:49 by bdomansk          #+#    #+#              #
#    Updated: 2018/04/23 11:55:51 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../push_swap
LIB = ../libft/libft.a
LIBDIR = ../libft
FLAGS = -Wall -Wextra -Werror
PUSH_SWAP_SRC = main.c ft_check_ps_flags.c ft_check_duplicate.c ft_rotate.c \
				ft_free_arr.c ft_ps_status.c ft_putstack.c ft_error.c \
				ft_reverse_rotate.c ft_push.c ft_swap.c ft_validate.c \
				ft_lstlen.c ft_comnd.c ft_simple_sorts.c  ft_push_stack_a.c \
				ft_sort.c ft_is_sort.c ft_putcommands.c ft_free_structures.c \
				ft_find.c ft_min_rotates.c ft_mini_sort.c
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
HEADER = ../push_swap.h
DEL = /bin/rm -f

.PHONY : all clean n fclean re

all : $(NAME)

$(NAME) : $(LIB) $(PUSH_SWAP_OBJ) 
	@echo "Compiling push_swap"
	@gcc $(FLAGS) $(PUSH_SWAP_OBJ) -o $(NAME) $(LIB)

$(PUSH_SWAP_OBJ): $(PUSH_SWAP_SRC)
	@echo "Push_swap objects creating"
	@gcc $(FLAGS) -c $(PUSH_SWAP_SRC)

$(LIB) :
	@make -C $(LIBDIR)

clean:
	@$(DEL) $(PUSH_SWAP_OBJ)

n :
	@norminette $(PUSH_SWAP_SRC) 

fclean:
	@$(DEL) $(PUSH_SWAP_OBJ)
	@$(DEL) $(NAME)
	
re: fclean all
