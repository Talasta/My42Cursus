NAME  =generator

SRC   =main.cpp Base.cpp
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
