CXX= c++

CXXFLAGS= -Wall -Werror -Wextra -std=c++98

NAME= DiamondTrap

SRC= ClapTrap.cpp main.cpp DiamondTrap.cpp FragTrap.cpp ScavTrap.cpp 

OBJ= $(SRC:.cpp=.o)


all: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $(@)


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)


re: fclean all
