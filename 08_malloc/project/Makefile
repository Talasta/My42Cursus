# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 11:28:01 by cmaxime           #+#    #+#              #
#    Updated: 2019/05/10 14:57:39 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINK = libft_malloc.so

SRC = map_alloc.c \
		map_search.c \
		print.c \
		show_alloc_mem.c \
		malloc.c \
		realloc.c \
		free.c

OBJ = $(SRC:%.c=.obj/%.o)

DEPS = Makefile include/malloc.h

INCLUDE = -I include
GCC = gcc
FLAG = -Wall -Wextra -Werror

# Formating
NORMAL=\x1b[0m
BOLD=\x1b[40m\x1b[1m

all: $(NAME)

$(NAME): .obj $(OBJ) $(DEPS)
	gcc -shared $(INCLUDE) -o $(NAME) $(OBJ)
	ln -sf $(NAME) $(LINK)
	@echo "$(BOLD)[ $(NAME) ] compiled $(NORMAL)"

.obj:
	mkdir .obj

.obj/%.o: src/%.c
	$(GCC) $(INCLUDE) -fPIC -c $< -o $@ $(FLAG)

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME) $(LINK)

re: fclean all

.PHONY: clean fclean all re
