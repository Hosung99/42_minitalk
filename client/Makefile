cc = cc
CFLAGS = -Wall -Wextra -Werror
NAME = client
SRCS_CLIENT = client.c ../ft_atoi.c ../ft_putchar_fd.c ../ft_putnbr_fd.c ../ft_putstr_fd.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

$(NAME): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_CLIENT)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJS_CLIENT)

re: fclean all

.PHONY: all clean fclean re