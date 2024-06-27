NAME = Polymorph

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -v
RM = rm -rf

HEAD = includes/Animal.hpp includes/Dog.hpp includes/Cat.hpp \
		includes/WrongAnimal.hpp includes/WrongCat.hpp
SRCS = main.cpp srcs/Animal.cpp srcs/Dog.cpp srcs/Cat.cpp \
		srcs/WrongAnimal.cpp srcs/WrongCat.cpp
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
