CXX= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp


NAME = HI_BRAIN


all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
