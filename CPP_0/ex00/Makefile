NAME = megaphone

# Compiler and flags
CXX = c++ # Can be replaced with g++ or clang++ if needed
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# Source files
SOURCES = megaphone.cpp

# Default target to build the program
all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(NAME)

# Clean up generated files
clean:
	rm -f $(NAME)

# Run the program
run: $(NAME)
	./$(NAME)

