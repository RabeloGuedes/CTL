CXX = c++
WFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iincludes
DFLAGS = -g
FLAGS = $(WFLAGS) $(IFLAGS) $(DFLAGS)

NAME = CTL.a

SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/

SRCS = Assert.cpp CTL.cpp Describe.cpp
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	mkdir -p $(OBJS_DIR)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
