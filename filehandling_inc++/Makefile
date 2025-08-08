CXX= c++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98

NAME= fileexploiting

SRC=main.cpp

OBJ=$(SRC:.cpp=.o)



$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all:$(NAME)
	echo nichan


%.o:%.cpp	
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
