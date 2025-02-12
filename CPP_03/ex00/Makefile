CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp ClapTrap.cpp helper.cpp
OBJ_DIR := obj
OBJS := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

NAME := battle

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(OBJ_DIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)
