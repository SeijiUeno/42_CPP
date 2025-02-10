NAME        =   SedIsForLosers
SRCS        =   $(wildcard src/*.cpp)
INCLUDE_FLS =   $(wildcard src/*.hpp) \
                $(wildcard include/*.hpp)
INCLUDES    =   -Isrc -Iinclude
CC          =   c++
FLAGS       =   -Wall -Wextra -Werror -std=c++98
VALGRIND    =   valgrind --leak-check=full --show-leak-kinds=all

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDE_FLS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS) -o $@

fclean:
	@ rm -rf $(NAME)

re: fclean all

run: $(NAME)
	./$< $(ARGS)

valgrind: $(NAME)
	$(VALGRIND) ./$< $(ARGS)
