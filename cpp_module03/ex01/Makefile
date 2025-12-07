CXX= c++

CXXFLAGS= -Wall -Werror -Wextra -std=c++98

NAME= ScavTrap

SRC= ClapTrap.cpp main.cpp ScavTrap.cpp 


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
