NAME = DiamondTrap

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
RM = rm -rf

HEADA = ScavTrap.hpp ClapTrap.hpp FragTrap.hpp DiamondTrap.hpp
SRCS = main.cpp ScavTrap.cpp ClapTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:%.cpp=$(D_OBJS)/%.o)
D_OBJS = obj
DEPS = $(SRCS:.cpp=.d)

all : $(NAME)

$(D_OBJS)/%.o : %.cpp Makefile $(HEAD)
	@mkdir -p $(D_OBJS)
	$(CC) $(FLAGS) -MMD -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(D_OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

-include $(DEPS)

.PHONY : all clean fclean re