CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRC_DIR := .
OBJ_DIR := obj

SRCS := $(SRC_DIR)/Zombie.cpp $(SRC_DIR)/randomChump.cpp $(SRC_DIR)/newZombie.cpp $(SRC_DIR)/main.cpp
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

NAME := BraiiiiiiinnnzzzZ

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re