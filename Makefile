.SUFFIXES : .c .o

NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Werror -Wextra
MEMORY  := -g3 -fsanitize=address
DEBUG   := -g

BLACK   := \033[30m
RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE    := \033[34m
MAGENTA := \033[35m
CYAN    := \033[36m
WHITE   := \033[37m
RESET   := \033[0m

LIBFT   := ./libft/libft.a
SRC_DIR := ./src
INCLUDE := -I./inc -I./libft/inc

SRC     := \
		main.c \
		deque.c \
		cmd_push.c \
		cmd_swap.c \
		cmd_rotate.c \
		parse.c \
		set_idx.c \
		sort.c \
		utils.c \
		find_min_rot.c \
		find_min_rot_utils.c
OBJ     := $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

BONUS_SRC_DIR := ./bonus/src
BONUS_INCLUDE := -I./bonus/inc

BONUS         := checker
BONUS_SRC     := \
		$(BONUS_SRC_DIR)/get_next_line_bonus.c \
		$(BONUS_SRC_DIR)/get_next_line_utils_bonus.c \
		$(BONUS_SRC_DIR)/checker_bonus.c \
		$(SRC_DIR)/deque.c \
		$(SRC_DIR)/cmd_push.c \
		$(SRC_DIR)/cmd_swap.c \
		$(SRC_DIR)/cmd_rotate.c \
		$(SRC_DIR)/parse.c \
		$(SRC_DIR)/set_idx.c \
		$(SRC_DIR)/sort.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/find_min_rot.c \
		$(SRC_DIR)/find_min_rot_utils.c
BONUS_OBJ     := $(BONUS_SRC:.c=.o)

all: $(NAME)
	@echo "$(GREEN)$(NAME) created successfully$(RESET)"

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(WHITE)Creating $@$(RESET)"

$(LIBFT):
	@$(MAKE) all -C ./libft

bonus: $(BONUS)
	@echo "$(GREEN)$(BONUS) created successfully$(RESET)"

$(BONUS): $(LIBFT) $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS)
	@echo "$(WHITE)Creating $@$(RESET)"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "$(CYAN)Compiled:$(RESET) $< -> $@"

$(BONUS_SRC_DIR)/%.o: $(BONUS_SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) $(BONUS_INCLUDE)
	@echo "$(CYAN)Compiled:$(RESET) $< -> $@"

clean:
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo "$(BLUE)Cleaned up object files$(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME) $(BONUS)
	@echo "$(BLUE)Cleaned up executable and library$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

mem:
	@$(MAKE) fclean
	@$(MAKE) mem -C ./libft
	@$(MAKE) all CFLAGS="$(CFLAGS) $(MEMORY)"
	@echo "$(YELLOW)Executable compiled with memory sanitizer$(RESET)"

lldb:
	@$(MAKE) fclean
	@$(MAKE) lldb -C ./libft
	@$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"
	@echo "$(YELLOW)Executable compiled to enable LLDB debugging$(RESET)"

.PHONY: all clean fclean re mem lldb bonus
