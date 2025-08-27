CXX= c++

CXXFLAGS= -Wall -Werror -Wextra -std=c++98

SRC= ClapTrap.cpp main.cpp

OBJ=$(SRC:.cpp=.o)

NAME=ClapTra.cpp

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	echo "NAME executed.........."

all:$(NAME)
	echo "all excuted ......... "

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean make

