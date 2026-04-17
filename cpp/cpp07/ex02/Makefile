NAME = array

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g3 -Iheader

RM = rm -f

GREEN	= \033[0;32m
YELLOW	= \033[0;33m
CYAN	= \033[0;36m
RESET	= \033[0m
BOLD	= \033[1m

SRCS =	src/main.cpp \

OBJS = $(patsubst src/%.cpp,%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)$(BOLD)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)✓ $(NAME) compiled successfully!$(RESET)"

%.o: src/%.cpp
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)Done.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)Done.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
