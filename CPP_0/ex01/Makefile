# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 17:43:59 by sueno-te          #+#    #+#              #
#    Updated: 2025/02/07 16:16:16 by sueno-te         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = main.cpp contact.cpp phoneBook.cpp
BUILD_DIR = temp
OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:.cpp=.o))

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
