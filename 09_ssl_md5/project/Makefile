# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 14:16:51 by cmaxime           #+#    #+#              #
#    Updated: 2019/05/28 14:02:22 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC := md5.c \
		md5_binop.c \
		md5_const.c \
		md5_mem.c \
		md5_print.c \
		sha256.c \
		sha256_binop.c \
		sha256_binrt.c \
		sha256_const.c \
		sha256_mem.c \
		sha256_print.c \
		sha384.c \
		sha512.c \
		sha512_binop.c \
		sha512_binrt.c \
		sha512_const.c \
		sha512_mem.c \
		sha512_print.c \
		ssl.c \
		ssl_argparser.c \
		ssl_argparser_def.c \
		ssl_argparser_mask.c \
		ssl_hash.c

OBJ := $(addprefix .obj/,$(SRC:.c=.o))

CXX := gcc
INCLUDES :=  -I include -I libft/include
CXXFLAGS := -Wall -Wextra -Werror -Weverything -pedantic
LIB := -L libft -lft

all : $(NAME)

$(NAME): .obj $(OBJ)
	$(MAKE) -C libft
	$(CXX) $(OBJ) -o $@ $(LIB)

libft:
	$(MAKE) -C libft

.obj:
	mkdir .obj

.obj/%.o: src/%.c
	$(CXX) $(INCLUDES) -o $@ $(CXXFLAGS) -c $<

clean:
	$(MAKE) clean -C libft
	rm -rf .obj

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
