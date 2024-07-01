# Color definitions
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET = \033[0m
BOLD = \033[1m

# Directory definitions
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = lib

# Add new folders here
SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIB = lib/libft/libft.a -L$(PWD)/lib/sdl2/build -lSDL2 -lSDL2_ttf

NAME = doom-nukem

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	# Linux specific flags
	LIB += -Wl,-rpath,$(PWD)/lib/sdl2/build
else ifeq ($(UNAME_S),Darwin)
	# macOS specific flags
	LIB += -Wl,-rpath,@executable_path/lib/sdl2/build
endif

CC = gcc
CFLAGS += -g -Wall -Wextra
CFLAGS += -I $(INC_DIR) -I lib/libft -I lib/sdl2/include -I lib/sdl2/build/include -I lib/sdl2_ttf

all: $(OBJ_DIR) $(LIB) $(NAME)

# Ensure object directories exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJS): | create_obj_dirs

create_obj_dirs:
	@mkdir -p $(dir $(OBJS))

# Pattern rule for compiling object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D) # Ensure the directory exists
	@$(CC) -c $< -o $@ $(CFLAGS)
	@echo "$(MAGENTA)Compiled $@$(RESET)"

$(LIB): sdl_init
	@make -C lib/libft
	@make -C lib/sdl2/build

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIB) -lm
	@echo "$(GREEN)Compiled { $(CYAN)$(NAME) $(GREEN)}$(RESET)"

run: $(NAME)
	@echo "$(GREEN)Running $(NAME)$(RESET)"
	@./$(NAME)

src: clean all

# Reset SDL
sdl_reset: sdl_del sdl_init

# Delete SDL
sdl_del:
	@rm -rf lib/sdl2/build
	@rm -rf lib/sdl2_ttf/build

# Initialize SDL
sdl_init:
	@cmake -S lib/sdl2 -B lib/sdl2/build && cmake --build lib/sdl2/build
	@cmake -S lib/sdl2_ttf -B lib/sdl2_ttf/build && cmake --build lib/sdl2_ttf/build

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "$(YELLOW)Object directory $(RED)DELETED$(RESET)"

fclean: clean sdl_del
	@make fclean -C lib/libft
	@echo "$(YELLOW)$(NAME) $(RED)DELETED$(RESET)"

sclean: clean
	@make fclean -C lib/libft
	@echo "$(YELLOW)$(NAME) $(RED)DELETED$(RESET)"


re: fclean all

sre: sclean all

.PHONY: all clean fclean re sdl_reset sdl_del sdl_init run