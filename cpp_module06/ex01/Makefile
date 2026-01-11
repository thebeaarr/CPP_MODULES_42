CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Serializer.cpp


OBJS = $(SRCS:.cpp=.o)


NAME =Serializer

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@



clean : 
	rm -rf $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all
