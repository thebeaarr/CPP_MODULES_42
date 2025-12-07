CXX=c++

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

NAME=polymorph

SRCS=Animal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp 

OBJS=$(SRCS:.cpp=.o)

all: $(NAME) $(NAME_W)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)


clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all