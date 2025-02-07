NAME = GlobalBanksters

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = tests.cpp account.cpp
BUILD_DIR = temp
OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:.cpp=.o))

# Targets
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run
