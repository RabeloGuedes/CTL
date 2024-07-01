CXX = c++
WFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iincludes
DFLAGS = -g
VFLAGS = -std=c++20
FLAGS = $(WFLAGS) $(IFLAGS) $(DFLAGS) $(VFLAGS)

NAME = CTL.a

SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/

SRCS = Assert.cpp CTL.cpp
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
