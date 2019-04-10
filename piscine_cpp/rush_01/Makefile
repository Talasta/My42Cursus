NAME = ft_gkrellm

OBJ := $(subst src,.obj,$(subst .cpp,.o,$(wildcard src/*)))

CXX := clang++
CXXFLAGS :=  -I include -I ~/.brew/Cellar/sfml/2.5.1/include  -Wall -Wextra -Werror
SFMLFLAGS :=  -L ~/.brew/Cellar/sfml/2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
LIB := -lncurses

all : $(NAME)

$(NAME) : .obj $(OBJ)
	export LD_LIBRARY_PATH=~/.brew/Cellar/sfml/2.5.1/lib
	$(CXX) -o $@ $(LIB) $(OBJ) $(SFMLFLAGS)
.obj:
	mkdir .obj

.obj/%.o: src/%.cpp
	$(CXX) -o $@ $(CXXFLAGS) -c $<

-include $(OBJ:.o=.d)

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
