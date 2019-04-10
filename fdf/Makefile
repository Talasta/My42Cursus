# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 11:28:01 by cmaxime           #+#    #+#              #
#    Updated: 2017/12/06 15:01:25 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAG = -Wall -Wextra -Werror

SRC = ./fdf.c \
	./set_color.c \
	./set_line.c \
	./set_img_pxl.c \
	./fdf_multimap.c \
	./fdf_keys.c \
	./fdf_info.c \
	./fdf_init.c \
	./fdf_store_map.c \
	./fdf_color_config.c \
	./fdf_map_to_img.c \
	./fdf_map_cpy.c \
	./fdf_set_pos.c \
	./fdf_key_f1.c \
	./fdf_key_f2.c \
	./fdf_key_f3.c \
	./fdf_key_f4.c \
	./fdf_key_f5.c 

OBJ = $(SRC:%.c=%.o)

DEPS = ./includes/fdf.h \
	   ./includes/fdf_key.h \
	   ./Makefile

INCLUDE = includes
LIBFT = -lft
LIBMLX = -lm -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	$(MAKE) -C ./libft
	gcc $(OBJ) -o $@ -L./libft $(LIBFT) $(LIBMLX) $(FLAG)

%.o: %.c
	gcc -I$(INCLUDE) -c $< -o $@ $(FLAG)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
