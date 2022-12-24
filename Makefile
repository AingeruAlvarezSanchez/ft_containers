#SHELL = /bin/zsh

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address
CXX = clang++

SRCS =	main.cpp	\
		STLmain.cpp

OBJS = $(SRCS:.cpp=.o)

.SILENT:

all: $(OBJS)
	$(CXX) $(CXXFLAGS) main.o -o mytests
	$(CXX) $(CXXFLAGS) STLmain.o -o STLtests

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) mytests
	$(RM) STLtests

re: clean all

.PHONY: all clean re