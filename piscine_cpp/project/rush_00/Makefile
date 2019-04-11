NAME := ft_retro
OBJ := $(subst src,.obj,$(subst .cpp,.o,$(wildcard src/*)))

CXX := clang++
NOW := $(addprefix -Wno-,exit-time-destructors global-constructors float-equal)
CXXFLAGS := -MMD -Iinclude -Weverything -Wall -Wextra -Werror -ansi -pedantic $(NOW)
LIBS := $(addprefix -l,ncurses)

all : $(NAME)

$(NAME) : .obj $(OBJ)
	$(CXX) -o $@ $(LIBS) $(OBJ)

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
