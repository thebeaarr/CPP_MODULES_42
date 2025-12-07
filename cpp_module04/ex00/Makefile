CXX=c++

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

NAME=polymorph
NAME_W=wrong_polymorph

SRCS=Animal.cpp Cat.cpp Dog.cpp main.cpp
WSRCS=WrongAnimal.cpp WrongCat.cpp wrong_main.cpp

OBJS=$(SRCS:.cpp=.o)
WOBJS=$(WSRCS:.cpp=.o)

all: $(NAME) $(NAME_W)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(NAME_W): $(WOBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME_W) $(WOBJS)

clean:
	@rm -f $(OBJS) $(WOBJS)

fclean: clean
	@rm -f $(NAME) $(NAME_W)

re: fclean all