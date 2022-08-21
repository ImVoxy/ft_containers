NAME = tests

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -DTEST=ft
# CFLAGS = -std=c++11 -Wall -Wextra -Werror -DTEST=std

INC = srcs/map/includes/ srcs/vector/includes/ srcs/stack/includes/ srcs/others/includes 
TEST = ./tests

SRCDIR = srcs/
OBJDIR = .obj/
D = .dep/

SRCS =		stack_main.cpp \
		vector_main.cpp \
		map_main.cpp \
		pair_main.cpp \
		iterator_main.cpp \
		reverse_iterator_main.cpp \
		main.cpp \
		lexicographical_compare_main.cpp \
		is_integral_main.cpp \
		enable_if_main.cpp

CFLAGS		+= $(addprefix -I,$(INC))
SRCS		:= $(addprefix $(SRCDIR),$(SRCS))
OBJS		:= $(SRCS:$(SRCDIR)%=$(OBJDIR)%.o)
DEPS		:= $(SRCS:$(SRCDIR)%=$(D)%.d)
DEPFLAGS	= -MT $(@:$(OBJDIR)%.o=$(SRCDIR)%) -MMD -MP -MF $D$*.d

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $^ -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

$(D):
	@mkdir $(D)

$(OBJS): $(OBJDIR)%.o:$(SRCDIR)% | $(OBJDIR) $(D)
	@mkdir -p $(@D)
	@mkdir -p $(@D:$(OBJDIR)%=$(D)%)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $(@:$(OBJDIR)%.o=$(SRCDIR)%) -o $@

exec:
	all ; $(TEST)

valgrind:
	all ; valgrind $(TEST)

clean:
	rm -rf $(OBJDIR)
	rm -rf $D

fclean: clean
	rm -rf $(NAME) a.out

re: clean fclean all

DEPFILES := $(SRCS:%.cpp=$D/%.d)
$(DEPFILES):

include $(DEPFILES)
