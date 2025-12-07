CXX=c++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98

SRC= main.cpp


NAME=Sed_is_for_losers

all:$(NAME)

$(NAME): $(SRC)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)


fclean:
	@rm -rf $(NAME)
	@echo executable removed...

re: fclean all
