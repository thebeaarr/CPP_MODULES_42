CXX=c++

CXXFLAGS= -Wall -Werror -Wextra -std=c++98

SRCS=Harl.cpp main.cpp

OBJS=$(SRCS:.cpp=.o)

NAME=harlFilter


all:$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
