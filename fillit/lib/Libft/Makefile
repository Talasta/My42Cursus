# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:06:06 by blefeuvr          #+#    #+#              #
#    Updated: 2017/11/17 20:35:48 by blefeuvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -I .
FLAGS = -Werror -Wall -Wextra
OBJ =\
	ft_ulstsize.o\
	ft_ulsttsize.o\
	ft_atoi.o\
	ft_bzero.o\
	ft_isalnum.o\
	ft_isalpha.o\
	ft_isascii.o\
	ft_isdigit.o\
	ft_isprint.o\
	ft_itoa.o\
	ft_lstadd.o\
	ft_lstaddend.o\
	ft_lstdel.o\
	ft_lstdel.o\
	ft_lstdelone.o\
	ft_lstiter.o\
	ft_lstmap.o\
	ft_lstnew.o\
	ft_lstsize.o\
	ft_memalloc.o\
	ft_memccpy.o\
	ft_memchr.o\
	ft_memcmp.o\
	ft_memcpy.o\
	ft_memdel.o\
	ft_memmove.o\
	ft_memset.o\
	ft_putchar.o\
	ft_putchar_fd.o\
	ft_putendl.o\
	ft_putendl_fd.o\
	ft_putnbr.o\
	ft_putnbr_fd.o\
	ft_putstr.o\
	ft_putstr_fd.o\
	ft_sqrtup.o\
	ft_strcat.o\
	ft_strccount.o\
	ft_strchr.o\
	ft_strclr.o\
	ft_strcmp.o\
	ft_strcpy.o\
	ft_strdel.o\
	ft_strdup.o\
	ft_strequ.o\
	ft_striter.o\
	ft_striteri.o\
	ft_strjoin.o\
	ft_strlcat.o\
	ft_strlen.o\
	ft_strmap.o\
	ft_strmapi.o\
	ft_strncat.o\
	ft_strncmp.o\
	ft_strncpy.o\
	ft_strndup.o\
	ft_strnequ.o\
	ft_strnew.o\
	ft_strnstr.o\
	ft_strrchr.o\
	ft_strsplit.o\
	ft_strstr.o\
	ft_strsub.o\
	ft_strtrim.o\
	ft_tolower.o\
	ft_toupper.o\
	ft_ulstadd_head.o\
	ft_ulstadd_tail.o\
	ft_ulstdel.o\
	ft_ulstdelone.o\
	ft_ulstnew.o\
	ft_ulstset_head.o\
	ft_ulstset_tail.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
