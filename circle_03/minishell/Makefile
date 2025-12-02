# Program name
NAME = minishell

# Directories
SRC_DIR = srcs/c_files
OBJ_DIR = objs
INC_DIR = srcs/h_files
LIBFT_DIR = libs/libft
PRINTF_DIR = libs/ft_printf
GNL_DIR = libs/get_next_line

# Detect Readline installation path dynamically (for macOS compatibility)
READLINE_DIR := $(shell brew --prefix readline 2>/dev/null || echo "/usr")

# Compiler and flags
CC = cc -g -g3
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/includes \
         -I$(PRINTF_DIR)/includes -I$(GNL_DIR)/includes -I$(READLINE_DIR)/include
LDFLAGS = -L$(READLINE_DIR)/lib -lreadline -lhistory

# Sources and objects
SRCS = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/env_manager.c \
		$(SRC_DIR)/signals.c \
		$(SRC_DIR)/prompt_manager.c \
		$(SRC_DIR)/tokenizer_utils.c \
		$(SRC_DIR)/tokenizer_utils_2.c \
		$(SRC_DIR)/tokenizer.c \
		$(SRC_DIR)/parser.c \
		$(SRC_DIR)/parser_utils.c \
		$(SRC_DIR)/parser_utils_2.c \
		$(SRC_DIR)/parser_utils_3.c \
		$(SRC_DIR)/parser_utils_4.c \
		$(SRC_DIR)/parser_utils_5.c \
		$(SRC_DIR)/parser_utils_6.c \
		$(SRC_DIR)/parser_utils_7.c \
		$(SRC_DIR)/path_manager.c \
		$(SRC_DIR)/path_manager_utils.c \
		$(SRC_DIR)/built_in.c \
		$(SRC_DIR)/cd.c \
		$(SRC_DIR)/unset.c \
		$(SRC_DIR)/env.c \
		$(SRC_DIR)/echo.c \
		$(SRC_DIR)/export.c \
		$(SRC_DIR)/export_utils_2.c \
		$(SRC_DIR)/export_utils.c \
		$(SRC_DIR)/heredoc.c \
		$(SRC_DIR)/here_doc_utils.c \
		$(SRC_DIR)/heredoc_utils2.c \
		$(SRC_DIR)/expander.c \
		$(SRC_DIR)/expander_utils.c \
		$(SRC_DIR)/validator.c \
		$(SRC_DIR)/execute.c \
		$(SRC_DIR)/execute_utils_2.c \
		$(SRC_DIR)/execute_utils_3.c \
		$(SRC_DIR)/execute_utils.c \
		$(SRC_DIR)/handle.c \
		$(SRC_DIR)/apply.c

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
GNL_LIB = $(GNL_DIR)/get_next_line.a

# Build rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(GNL_LIB) $(LDFLAGS) -o $(NAME)

# Rule to compile source files into objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build libft.a
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build printf (libftprintf.a)
$(PRINTF):
	make -C $(PRINTF_DIR)

# Build get_next_line.a
$(GNL_LIB):
	make -C $(GNL_DIR)

# Clean object files and binary
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(GNL_DIR) clean

# Full clean, including all library builds
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(GNL_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
