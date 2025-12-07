CXX=c++

CXXFLAGS=-Wall -Werror -Wextra -std=c++98

SRC= bsp.cpp Fixed.cpp Point.cpp

NAME=bsp

OBJ=$(SRC:.cpp=.o)


$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)


%.o:%.cpp
	$(CXX) $(CXXFLAGS)  -c $<  -o $@


clean:
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re: fclean all

