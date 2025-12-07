# Compiler and flags
CXX = c++ -g
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Sources
SRCS = main.cpp \
       AMateria.cpp \
       Character.cpp \
       Cure.cpp \
       GagrbageColl.cpp \
       Ice.cpp \
       ICharacter.cpp \
       IMateriaSource.cpp \
       MateriaSource.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
NAME = ex03

# Default target
all: $(NAME)

# Build executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile source files into objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean objects + executable
fclean: clean
	rm -rf $(NAME)