CXX= c++ 
CXXFLAGS= -Wall -Werror -Wextra --std=c++98



NAME=btc 



SRC= main.cpp

OBJ = $(SRC:.cpp=.o)
HEADER = BitcoinExchange.hpp



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