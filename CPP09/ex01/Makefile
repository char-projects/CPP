NAME					=	RPN

SRC						=	main.cpp RPN.cpp

OBJ 					= 	$(SRC:.cpp=.o)

CFLAGS					=	-Werror -Wextra -Wall -std=c++98

%.o						: 	%.cpp
							c++ $(CFLAGS) -c $< -o $@

all						:	$(NAME)

$(NAME)					:	$(OBJ)
							c++ $(CFLAGS) -o $(NAME) $(OBJ)

clean					:
							rm -rf $(OBJ)

fclean					:	clean
							rm -rf $(NAME) 

re						:	fclean all

.PHONY					:	all clean fclean re
