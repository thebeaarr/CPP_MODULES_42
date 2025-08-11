CXX=c++

CXXFLAGS= -Wall -Werror -Wextra -std=c++98


SRC= main.cpp Fixed.cpp


NAME=Fixed

all:$(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)


clean:
	@rm -rf *.o
	@echo cleaning object files

fclean: clean
	rm -rf $(NAME)

re: fclean all


