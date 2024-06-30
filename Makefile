CXX = c++
WFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iincludes
DFLAGS = -g
FLAGS = $(WFLAGS) $(IFLAGS) $(DFLAGS)

NAME = CTL.a
OBJS_DIR = ./objs/

SRCS = Assert.cpp CTL.cpp Describe.cpp
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS_DIR)%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CXX) $(FLAGS) -c $^

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
