CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

NAME =ScalarConverter

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fclean:
	rm -f $(NAME)

re: fclean all