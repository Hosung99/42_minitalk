/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:20:14 by seoson            #+#    #+#             */
/*   Updated: 2023/09/18 17:16:46 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	temp;
	char		print;

	temp = (long long)n;
	if (temp < 0)
	{
		temp *= -1;
		write(fd, "-", 1);
	}
	if (temp > 9)
		ft_putnbr_fd(temp / 10, fd);
	print = (temp % 10) + '0';
	write(fd, &print, 1);
}
