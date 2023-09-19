cc = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_sig_error.c
OBJS = $(SRCS:.c=.o)

all: run-server run-client

run-server:
	make -C server

run-client:
	make -C client

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)
	make -C server clean
	make -C client clean

fclean: clean
	rm -f $(OBJS)
	make -C server fclean
	make -C client fclean

re: fclean all

.PHONY: all clean fclean re run-server run-client