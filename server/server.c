/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:02:45 by seoson            #+#    #+#             */
/*   Updated: 2023/09/18 18:09:10 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	print_pid(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void	print_server(int sig, siginfo_t *si, void *context)
{
	static int	res;
	static int	cnt;

	(void)si;
	(void)context;
	if (sig == SIGUSR1)
		res = (res << 1) | 1;
	else if (sig == SIGUSR2)
		res = res << 1;
	cnt++;
	if (cnt == 8)
	{
		ft_putchar_fd((char)res, 1);
		cnt = 0;
		res = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;

	if (argc != 1)
	{
		write(2, "Argument Error\n", 15);
		return (-1);
	}
	(void)argv;
	print_pid();
	sigemptyset(&(act.sa_mask));
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	act.sa_sigaction = print_server;
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		ft_sig_error();
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		ft_sig_error();
	while (1)
		pause();
}
