/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:00:04 by oscar             #+#    #+#             */
/*   Updated: 2022/11/28 11:00:35 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}

static int	ft_isprint_extended(int c)
{
	if ((c >= 32 && c <= 126) || (c >= 9 && c <= 13))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static void	process_signal(int signal, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;
	unsigned char			p;

	(void)context;
	if (signal == SIGUSR2)
		c = c | 1;
	i++;
	if (i == 8)
	{
		p = c;
		c = 0;
		i = 0;
		if (ft_isprint_extended(p))
			ft_putchar_fd(p, 1);
		else
		{
			kill(info->si_pid, SIGUSR1);
			return ;
		}
	}
	else
		c = c << 1;
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	action.sa_sigaction = process_signal;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
	{
		pause();
	}
	return (0);
}
