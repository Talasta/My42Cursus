#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 18:19:07 by cmaxime           #+#    #+#              #
#    Updated: 2018/02/15 14:07:29 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

all: $(NAME)

$(NAME):
	$(MAKE) -C ./checker_d
	$(MAKE) -C ./push_swap_d

clean:
	$(MAKE) clean -C ./checker_d
	$(MAKE) clean -C ./push_swap_d
	
fclean: clean
	$(MAKE) fclean -C ./checker_d
	$(MAKE) fclean -C ./push_swap_d

re: fclean all

.PHONY: all clean fclean re
