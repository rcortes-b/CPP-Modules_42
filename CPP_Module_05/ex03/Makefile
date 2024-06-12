NAME = FormOP

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf

HEAD = includes/Bureaucrat.hpp includes/AForm.hpp includes/ShrubberyCreationForm.hpp \
		includes/RobotomyRequestForm.hpp includes/PresidentialPardonForm.hpp includes/Intern.hpp
SRCS = main.cpp srcs/Bureaucrat.cpp srcs/AForm.cpp srcs/ShrubberyCreationForm.cpp \
		srcs/RobotomyRequestForm.cpp srcs/PresidentialPardonForm.cpp srcs/Intern.cpp
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