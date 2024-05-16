NAME = ClapTrap

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADA = ClapTrap.hpp
SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o : %.cpp Makefile $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re