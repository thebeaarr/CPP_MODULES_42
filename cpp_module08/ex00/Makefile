CXX= c++ -Wall -Werror -Wextra --std=c++98



NAME=  iter



SRC= main.cpp

OBJ = $(SRC:.cpp=.o)
HEADER = easyfind.hpp



all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CXX) $(OBJ) -o $(NAME)



%.o : %.cpp
	$(CXX) -c $< -o $@


clean :	
	rm -rf $(OBJ)


fclean : clean 
	rm -rf $(NAME)

re : clean all