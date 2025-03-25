NAME = bureaucrat_AForm

SRCDIR = src
INCDIR = include
CONCRETE = concrete

SRCS_MAIN = $(SRCDIR)/Bureaucrat.cpp $(SRCDIR)/AForm.cpp $(SRCDIR)/main.cpp

SRCS_CONCRETE = $(SRCDIR)/$(CONCRETE)/ShrubberyCreationForm.cpp \
                $(SRCDIR)/$(CONCRETE)/RobotomyRequestForm.cpp \
                $(SRCDIR)/$(CONCRETE)/PresidentialPardonForm.cpp

SRCS = $(SRCS_MAIN) $(SRCS_CONCRETE)

OBJS = obj/Bureaucrat.o obj/AForm.o obj/main.o \
       obj/$(CONCRETE)/ShrubberyCreationForm.o \
       obj/$(CONCRETE)/RobotomyRequestForm.o \
       obj/$(CONCRETE)/PresidentialPardonForm.o

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I $(INCDIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

obj/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re