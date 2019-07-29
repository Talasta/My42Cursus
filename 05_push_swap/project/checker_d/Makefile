# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 18:27:40 by cmaxime           #+#    #+#              #
#    Updated: 2018/01/30 12:27:11 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
FLAG = -Wall -Werror -Wextra
INC = ./includes
FSC = ./srcs/
CSC = ../srcs/
LIB = ./lib/

CSR = 	ft_strisdigit.c \
		ps_destroy_data.c \
		ft_atointmax.c \
		ft_lstgetlast.c \
		ps_lstpushback.c \
		ps_print_piles.c \
		ps_isint.c \
		ps_fetch_pile.c \
		ft_realloc_strtab.c \
		ps_swap.c \
		ps_push.c \
		ps_rotate.c \
		ps_rotate_rev.c

SRC =	ps_opexe.c \
		ps_view_controler.c \
		ps_image_drawer.c \
		ps_mlx.c \
		ps_draw.c \
		checker.c

OBJ = $(SRC:%.c=%.o)
COB = $(CSR:%.c=%.o)

DEP = ./Makefile \
	  $(INC)/libft.h \
	  $(INC)/checker.h

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(COB) $(DEP)
	@$(MAKE) -C ../libft
	@gcc $(OBJ) $(COB) -o $(NAME) -L$(LIB) -lft $(MLX) $(FLAG)
	@mv $(NAME) ..
	@echo "./checker compiled..."

%.o: $(CSC)%.c
	@gcc -I$(INC) -c $< -o $@ $(FLAG)

%.o: $(FSC)%.c
	@gcc -I$(INC) -c $< -o $@ $(FLAG)


clean:
	@$(MAKE) clean -C ../libft
	@rm -f $(OBJ) $(COB)
	@echo "Objects removed in checker_d/ ..."

fclean: clean
	@$(MAKE) fclean -C ../libft
	@rm -f ../$(NAME)
	@echo "./checker removed ..."


re: fclean all

.PHONY: re all clean fclean
