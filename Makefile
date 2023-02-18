#SHELL = /bin/bash

NAME = ft_containers

CXXFLAGS = -std=c++98 -pedantic -Wshadow=local -foptimize-sibling-calls -g3 -fsanitize=address ##TODO wall werro wextra

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $< -o $@

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
