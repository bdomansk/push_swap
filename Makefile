# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:48:14 by bdomansk          #+#    #+#              #
#    Updated: 2017/12/17 18:51:01 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
LIB = libft/libft.a
LIBDIR = libft
CHECKERDIR = src_checker
PUSH_SWAPDIR = src_push_swap
FLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
DEL = /bin/rm -f

.PHONY : all clean n fclean re

all : $(CHECKER) $(PUSH_SWAP)

$(CHECKER) : $(LIB)
	@make -C $(CHECKERDIR)

$(PUSH_SWAP) : $(LIB)
	@make -C $(PUSH_SWAPDIR)

clean:
	@make -C $(CHECKERDIR)/ clean
	@make -C $(PUSH_SWAPDIR)/ clean
	@make -C $(LIBDIR)/ clean

$(LIB) :
	@make -C $(LIBDIR)

n :
	@norminette $(HEADER)
	@make -C $(CHECKERDIR)/ n
	@make -C $(PUSH_SWAPDIR)/ n

fclean:
	@make -C $(LIBDIR)/ fclean
	@make -C $(CHECKERDIR)/ fclean
	@make -C $(PUSH_SWAPDIR)/ fclean

re: fclean all

