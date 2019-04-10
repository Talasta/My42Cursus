# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:06:06 by blefeuvr          #+#    #+#              #
#    Updated: 2017/11/17 19:59:11 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Werror -Wall -Wextra -g

OBJ =\
	ft_tetridel.o\
	ft_bittotab.o\
	ft_lstupdate.o\
	ft_newtetra.o\
	ft_putresult.o\
	ft_inittracking.o\
	ft_putresult.o\
	ft_puttab.o\
	ft_resetptr.o\
	ft_addelem.o\
	ft_mlcpos.o\
	ft_newmatrix.o\
	ft_mapbackup.o\
	ft_findmap.o\
	fillit.o\
	ft_readfile.o\
	ft_put.o\
	ft_power.o\
	ft_addtetri.o\
	ft_newmap.o\
	ft_printbit.o\
	ft_printmap.o\
	ft_tetribit.o\
	ft_checkpos.o\
	ft_comparemap.o\
	ft_reversemap.o\
	ft_putresult.o\
	ft_tetratl.o\
	ft_isquadra.o\
	ft_reco.o\

INCLUDE = ./include
LIB = ./lib/Libft

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB)
	gcc -L$(LIB) $^ -o $@ -lft

%.o: %.c
	$(CC) -I$(INCLUDE) -c $< -o $@ $(FLAGS)

clean:
	@$(MAKE) clean -C $(LIB)
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
