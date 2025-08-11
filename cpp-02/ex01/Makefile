CXX=c++

CXXFLAGS= -Wall -Werror -Wextra -std=c++98
NAME= Fixed

SRC= main.cpp  Fixed.cpp

all:$(NAME)


$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean :
	@echo object files cleaned

fclean : clean
	@rm -rf $(NAME)
	@echo excutable removed

make re : clean all 
