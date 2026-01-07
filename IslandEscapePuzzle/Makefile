CXX = c++
NAME = exe
CXXFLAGS = -Wall -Wextra -g -O2 -foptimize-sibling-calls
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) input.txt
	$(CXX) $(CXXFLAGS) -o $@ $<
clean :
	rm -f $(OBJ)

fclean :
	rm -f $(OBJ) $(NAME)

re : clean all

.PHONY : all clean re
