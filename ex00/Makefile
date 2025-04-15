NAME					=	megaphone

SRC						=	megaphone.cpp

OBJ 					= 	$(SRC:.cpp=.o)

CFLAGS					=	-Werror -Wextra -Wall -std=c++98

%.o						: 	%.cpp
							g++ $(CFLAGS) -c $< -o $@

all						:	$(NAME)

$(NAME)					:	$(OBJ)
							g++ $(CFLAGS) -o $(NAME) $(OBJ)

clean					:
							rm -rf $(OBJ)

fclean					:	clean
							rm -rf $(NAME) 

re						:	fclean all

.PHONY					:	all clean fclean re
