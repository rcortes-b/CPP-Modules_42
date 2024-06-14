NAME = RealType

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf

HEAD = includes/Base.hpp includes/RealType.hpp \
		includes/A.hpp includes/B.hpp includes/C.hpp
SRCS = main.cpp srcs/Base.cpp srcs/RealType.cpp \
		srcs/A.cpp srcs/B.cpp srcs/C.cpp
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