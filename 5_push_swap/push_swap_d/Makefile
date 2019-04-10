# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 18:27:40 by cmaxime           #+#    #+#              #
#    Updated: 2018/02/19 17:59:09 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAG = -Wall -Werror -Wextra
INC = ./includes
FSC = ./srcs/
CSC = ../srcs/
LIB = ./lib/

CSR = 	ft_strisdigit.c \
		ft_atointmax.c \
		ft_lstgetlast.c \
		ps_print_piles.c \
		ps_destroy_data.c \
		ps_lstpushback.c \
		ps_isint.c \
		ps_fetch_pile.c \
		ps_swap.c \
		ft_realloc_strtab.c \
		ps_push.c \
		ps_rotate.c \
		ps_rotate_rev.c

SRC	=   ps_op_find.c \
		ps_check1.c \
		ps_check2.c \
		ps_low.c \
		ps_fast.c \
		ps_fast_p1.c \
		ps_opadd1.c \
		ps_opadd2.c \
		ps_radix_sort.c \
		ps_quick_sort.c \
		ps_quick_sort_p1.c \
		ps_quick_sort_p2.c \
		ps_quick_sort_p3.c \
		ps_cmd_cleaner.c \
		ps_round_check.c \
		ps_sorted_pile.c \
		push_swap.c

OBJ = $(SRC:%.c=%.o)
COB = $(CSR:%.c=%.o)

DEP = ./Makefile \
	  $(INC)/libft.h \
	  $(INC)/push_swap.h

all: $(NAME)

$(NAME): $(OBJ) $(COB) $(DEP)
	@$(MAKE) -C ../libft
	@gcc $(OBJ) $(COB) -o $(NAME) -L$(LIB) -lft
	@mv $(NAME) ..
	@echo "./push_swap compiled..."

%.o: $(CSC)%.c
	@gcc -I$(INC) -c $< -o $@ $(FLAG)

%.o: $(FSC)%.c
	@gcc -I$(INC) -c $< -o $@ $(FLAG)

clean:
	@$(MAKE) clean -C ../libft
	@rm -f $(OBJ) $(COB)
	@echo "Objets removed in ./push_swap_d/ ..."

fclean: clean
	@$(MAKE) fclean -C ../libft
	@rm -f ../$(NAME)
	@echo "./push_swap removed..."

re: fclean all

.PHONY: re all clean fclean
