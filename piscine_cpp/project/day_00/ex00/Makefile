# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 10:22:32 by cmaxime           #+#    #+#              #
#    Updated: 2019/03/25 10:30:01 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  =megaphone

SRC   =megaphone.cpp
GCC   =clang++
FLAGS =-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) Makefile
	$(GCC) $(FLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
