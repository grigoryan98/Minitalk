/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:48:59 by tumolabs          #+#    #+#             */
/*   Updated: 2021/10/27 01:34:58 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int		g_counter = 0;
char	g_char = 0;

//g_counter = 0;
//g_char = 0;

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
		}
		n *= -1;
	}
	if ((n / 10) > 0)
		ft_putnbr_fd(n / 10, fd);
	if (n != -2147483648)
		ft_putchar_fd(n % 10 + '0', fd);
}

void	receiver_handler(int signum)
{
	g_char = g_char << 1;
	if (signum == SIGUSR1)
	{
		g_char = g_char | 1;
	}
	g_counter++;
	if (g_counter == 7)
	{
		write (1, &g_char, 1);
		g_char = 0;
		g_counter = 0;
	}
}

int	main(void)
{
	int		pid;

	pid = getpid ();
	ft_putnbr_fd (pid, 1);
	while (1)
	{
		signal (SIGUSR1, receiver_handler);
		signal (SIGUSR2, receiver_handler);
		pause();
	}
	return (0);
}
