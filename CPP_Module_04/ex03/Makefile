NAME = AbstractMateria

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf

HEAD = includes/AMateria.hpp includes/Cure.hpp includes/Ice.hpp \
		includes/ICharacter.hpp includes/Character.hpp \
		includes/IMateriaSource.hpp includes/MateriaSource.hpp
SRCS = main.cpp srcs/AMateria.cpp srcs/Cure.cpp srcs/Ice.cpp \
		srcs/ICharacter.cpp srcs/Character.cpp \
		srcs/IMateriaSource.cpp srcs/MateriaSource.cpp

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