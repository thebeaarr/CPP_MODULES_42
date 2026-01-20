CXX = c++


CXXFLAGS = -Wall -Werror -Wextra --std=c++98

NAME = Array

SRC= main.cpp



HEADER=Array.hpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)


$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	

clean : 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
