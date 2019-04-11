NAME := Mindopen
OBJ := $(subst src,.obj,$(subst .cpp,.o,$(wildcard src/*)))

CXX := clang++
CXXFLAGS :=  -Iinclude -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : .obj $(OBJ)
	$(CXX) -o $@ $(OBJ)

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
