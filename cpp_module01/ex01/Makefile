CXX= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp   Zombie.cpp  zombieHorde.cpp

NAME = Moar_brainz

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)


fclean:
	rm -f $(NAME)

re: fclean all
