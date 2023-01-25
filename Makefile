#SHELL = /bin/bash

NAME = ft_containers

CXXFLAGS = -Wall -Werror -Wextra #-std=c++98 -Wshadow -Wno-shadow -g3

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