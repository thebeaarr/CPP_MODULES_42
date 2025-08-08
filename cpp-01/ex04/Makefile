CXX=c++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98

SRC= main.cpp

OBJ=$(SRC:.cpp=.o)

NAME=mfile

all:$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)


%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

