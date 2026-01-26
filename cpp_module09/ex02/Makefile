NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp PmergeMe.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "=== Test 1: Small sequence ==="
	./$(NAME) 3 5 9 7 4
	@echo ""
	@echo "=== Test 2: Reverse order ==="
	./$(NAME) 9 8 7 6 5 4 3 2 1
	@echo ""
	@echo "=== Test 3: Already sorted ==="
	./$(NAME) 1 2 3 4 5
	@echo ""
	@echo "=== Test 4: Large sequence ==="
	./$(NAME) 12 3 10 5 8 2 6 1 15 4 11 7 14 9 13
	@echo ""
	@echo "=== Test 5: Duplicates ==="
	./$(NAME) 5 5 3 3 1 1
	@echo ""
	@echo "=== Test 6: Error - negative number ==="
	-./$(NAME) 5 -3 9
	@echo ""
	@echo "=== Test 7: Error - invalid character ==="
	-./$(NAME) 5 3 abc

.PHONY: all clean fclean re test