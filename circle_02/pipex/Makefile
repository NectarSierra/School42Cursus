FLAGS = -Wall -Wextra -Werror
NAME = pipex
LIBFT_A = ./libft/libft.a
SRCS_BONUS = ./srcs/bonus/main_bonus.c\
	   ./srcs/bonus/redirect_cmd_bonus.c\
	   ./srcs/bonus/path_cmd_bonus.c\
	   ./srcs/bonus/errors_handler_bonus.c\
	   ./srcs/bonus/utils_bonus.c\

SRCS = ./srcs/main.c\
	   ./srcs/redirect_cmd.c\
	   ./srcs/path_cmd.c\
	   ./srcs/errors_handler.c\
	   ./srcs/utils.c\

$(NAME): $(SRCS)
	cd ./libft/ && make bonus
	clear
	cc $(FLAGS) $(SRCS) ./libft/libft.a -o $(NAME)

bonus: $(SRCS_BONUS)
	cd ./libft/ && make bonus
	clear
	cc $(FLAGS) $(SRCS_BONUS) ./libft/libft.a -o $(NAME)

re: fclean $(NAME)

all: $(NAME)

clean:
	cd ./libft/ && make clean

fclean:
	cd ./libft/ && make fclean
	rm -rf $(NAME)
	