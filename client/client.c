/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:02:47 by seoson            #+#    #+#             */
/*   Updated: 2023/09/18 17:15:32 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_bit(int server_pid, char c)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		if ((c >> bits) & 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_putstr_fd("SIGUSR1 Error\n", 2);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_putstr_fd("SIGUSR2 Error\n", 2);
		}
		usleep(100);
		bits--;
	}
}

void	send_message(int pid, char *str)
{
	int	server_pid;
	int	str_index;

	server_pid = pid;
	str_index = 0;
	while (str[str_index])
		send_bit(server_pid, str[str_index++]);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		write(2, "Argument Error\n", 15);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "PID Error\n", 14);
		return (-1);
	}
	send_message(pid, argv[2]);
	send_message(pid, "\n");
	return (0);
}
