NAME = harlFilter

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADA = Harl.hpp
SRCS = main.cpp Harl.cpp
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