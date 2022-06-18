NAME = tests

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
INC = -Iincludes
TEST = ./tests

SRCDIR = srcs/

SRCS = 		stack_main.cpp \
		vector_main.cpp \
		pair_main.cpp \
		iterator_main.cpp \
		reverse_iterator_main.cpp \
		main.cpp \
		lexicographical_compare_main.cpp \
		is_integral_main.cpp \
		enable_if_main.cpp
		

OBJDIR = obj/

OBJ = $(addprefix $(OBJDIR),$(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) $(OBJ) -o $(NAME)

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

exec: all ;$(TEST)

valgrind: all ; valgrind $(TEST)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME) a.out

re: clean fclean all
