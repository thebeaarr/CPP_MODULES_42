CXX=c++

CXXFLAGS= -Wall -Werror -Wextra -std=c++98

SRCS=Harl.cpp main.cpp

NAME=harl


all:$(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean:
	rm -rf $(NAME)

re: fclean all
