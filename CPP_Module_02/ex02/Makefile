NAME = weTalking

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADA = Fixed.hpp
SRCS = main.cpp Fixed.cpp
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