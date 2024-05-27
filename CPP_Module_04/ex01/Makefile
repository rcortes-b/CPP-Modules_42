NAME = WorldOnFire

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEAD = includes/Animal.hpp includes/Dog.hpp includes/Cat.hpp \
		includes/Brain.hpp
SRCS = main.cpp srcs/Animal.cpp srcs/Dog.cpp srcs/Cat.cpp \
		srcs/Brain.cpp
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