# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 11:28:01 by cmaxime           #+#    #+#              #
#    Updated: 2018/01/22 17:51:11 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror

SRC = ft_printf.c \
	  ft_realloc_mem.c \
	  pf_declarations.c \
	  pf_wchar_to_char.c \
	  pf_precision.c \
	  pf_size.c \
	  pf_exception_zero.c \
	  pf_collapse_buff.c \
	  pf_arg_int.c \
	  pf_arg_uint.c \
	  pf_arg_uint2.c \
	  pf_arg_str.c \
	  pf_arg_ptr.c \
	  pf_arg_chr.c \
	  pf_arg_arg.c \
	  pf_arg_def.c \
	  pf_va_arg.c \
	  pf_init_t_print.c \
	  pf_t_print_cleaning.c \
	  pf_ltoa.c \
	  pf_op1.c \
	  pf_op2.c \
	  pf_core_parse.c

LIBFT = ft_newmatrix.c \
		get_next_line.c \
		ft_ulstadd_head.c \
		ft_ulstadd_tail.c \
		ft_ulstdel.c \
		ft_ulstdelone.c \
		ft_ulstnew.c \
		ft_ulstset_head.c \
		ft_ulstset_tail.c \
		ft_ulstsize.c \
		ft_ulsttsize.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memchr.c \
		ft_memccpy.c \
		ft_memdel.c \
		ft_memcmp.c \
		ft_putchar.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_putendl.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putstr.c \
		ft_strcat.c \
		ft_putnbr.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_strclr.c \
		ft_strcat.c \
		ft_strcmp.c \
		ft_strchr.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strequ.c \
		ft_strdup.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_strncat.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncpy.c \
		ft_strncmp.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strsplit.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_realloc.c \
		ft_pow.c

OBJ = $(SRC:%.c=%.o)
OBJLIBFT = $(LIBFT:%.c=%.o)

DEPS = ./Makefile \
	   ./includes/ft_printf.h \
	   ./includes/libft.h

INCLUDE = includes

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIBFT) $(DEPS)
	ar rc $(NAME) $(OBJ) $(OBJLIBFT)

%.o: libft/%.c
	gcc -I$(INCLUDE) -c $< -o $@ $(FLAG)

%.o: srcs/%.c
	gcc -I$(INCLUDE) -c $< -o $@ $(FLAG)

clean:
	rm -f $(OBJ) $(OBJLIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re target
