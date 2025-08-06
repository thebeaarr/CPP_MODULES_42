CXX= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp   Zombie.cpp  zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = Moar_brainz

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
