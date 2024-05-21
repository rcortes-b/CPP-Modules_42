NAME = DiamondTrap

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
RM = rm -rf

HEADA = ScavTrap.hpp ClapTrap.hpp FragTrap.hpp DiamondTrap.hpp
SRCS = main.cpp ScavTrap.cpp ClapTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all : $(NAME)

%.o : %.cpp Makefile $(HEAD)
	$(CC) $(FLAGS) -MMD -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

-include $(DEPS)

.PHONY : all clean fclean re