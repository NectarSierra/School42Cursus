NAME = libftprintf.a
DEPS = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

SRCS = 	ft_printf.c\
		ft_write_c.c\
		ft_write_s.c\
		ft_write_p.c\
		ft_write_d.c\
		ft_putnbr.c\
		ft_sizeputnbr.c\
		ft_tobase.c\
		ft_write_i.c\
		ft_write_u.c\
		ft_write_x.c\
		ft_write_xupp.c

OBJS = $(SRCS:.c=.o)

.c.o: $(SRCS)
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
