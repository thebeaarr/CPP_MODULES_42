CC= c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ph_func.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = phonebook


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
