CXX= c++ 
CXXFLAGS= -Wall -Werror -Wextra --std=c++98



NAME=RPN



SRC= main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)
HEADER = RPN.hpp



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