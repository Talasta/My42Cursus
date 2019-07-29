NAME = avm

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

SRC_FOLDER = src/
OBJ_FOLDER = .obj/

_SRC_FILES = \
			exceptions.cpp \
			instruction.cpp \
			ioperand.cpp \
			main.cpp \
			operand_factory.cpp \
			parserlexer.cpp \
			token.cpp \
			utils.cpp \
			virtual_machine.cpp \

SRC_FILES = $(addprefix $(SRC_FOLDER), $(_SRC_FILES))

CXX := clang++
CXX_FLAGS := -Wall -Wextra -Werror -Weverything -Wno-exit-time-destructors -Wno-global-constructors
CXX_STD := 
INC_FLAGS := -I include
LFLAGS := 
FLAGS := $(CXX_FLAGS) $(CXX_STD) $(INC_FLAGS) -MD

OBJ = \
		$(addprefix $(OBJ_FOLDER), $(_SRC_FILES:%.cpp=%.o)) \

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ_FOLDER) $(OBJ)
	@ printf "\\t%sLD%s\\t%s\\n" "$(_PURPLE)" "$(_END)" "$@"
	@$(CXX) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

$(OBJ_FOLDER):
	@mkdir $(OBJ_FOLDER)

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp Makefile
	@ printf "\\t%sCC%s\\t%s\\n" "$(_GREEN)" "$(_END)" "$<"
	@$(CXX) $(FLAGS) -c $< -o $@

DEP_FILES = $(OBJ:%.o=%.d)
-include $(DEP_FILES)

.PHONY: clean
clean:
	@ echo "Objects removed"
	@ rm -rf $(OBJ_FOLDER)

.PHONY: fclean
fclean: clean
	@ echo "Program $(NAME) removed"
	@ rm -rf $(NAME)

.PHONY: re
re:
	@ make fclean
	@ make all
