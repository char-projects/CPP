NAME					=	Interface

SRC						=	src/main.cpp src/AMateria.cpp src/Character.cpp src/Cure.cpp src/Ice.cpp src/Materia.cpp src/MateriaSource.cpp

OBJ 					= 	$(SRC:src/%.cpp=%.o)
OBJ_DIR					=	obj
OBJ_FILES				=	$(addprefix $(OBJ_DIR)/, $(OBJ))

CFLAGS					=	-Werror -Wextra -Wall -std=c++98 -Iinclude

$(OBJ_DIR)/%.o			: 	src/%.cpp
							@mkdir -p $(OBJ_DIR)
							c++ $(CFLAGS) -c $< -o $@

all						:	$(NAME)

$(NAME)					:	$(OBJ_FILES)
							@mkdir -p $(OBJ_DIR)
							c++ $(CFLAGS) -o $(NAME) $(OBJ_FILES)

clean					:
							rm -rf $(OBJ_DIR)

fclean					:	clean
							rm -rf $(NAME)

re						:	fclean all

.PHONY					:	all clean fclean re