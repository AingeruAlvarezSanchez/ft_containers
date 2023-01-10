#SHELL = /bin/zsh

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address

SRCS =	main.cpp

OBJS = $(SRCS:.cpp=.o)

.SILENT:

all: $(OBJS)
	$(CXX) $(CXXFLAGS) main.o -o myTests
	./ogTests > ogTests.txt
	./myTests > myTests.txt

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -D STL=1 -c $< -o $@
	$(CXX) $(CXXFLAGS) main.o -o ogTests
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) myTests
	$(RM) ogTests
	$(RM) *.txt

re: clean all

.PHONY: all clean re