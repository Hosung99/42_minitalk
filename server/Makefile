cc = cc
CFLAGS = -Wall -Wextra -Werror
NAME = server
SRCS_SERVER = server.c ../ft_putchar_fd.c ../ft_putnbr_fd.c ../ft_putstr_fd.c ../ft_sig_error.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_SERVER)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS_SERVER)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(OBJS_SERVER)

re: fclean all

.PHONY: all clean fclean re