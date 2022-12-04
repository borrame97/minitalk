/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:56:26 by oscar             #+#    #+#             */
/*   Updated: 2022/11/28 10:58:39 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received;

static void	process_received(int signal)
{
	if (signal == SIGUSR1)
	{
		g_received = 1;
	}
	if (signal == SIGUSR2)
	{
		g_received = 2;
	}
}

static void	process_char(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_received = 0;
		if (c >> i & 1)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		usleep(100);
		if (g_received == 1)
		{
			i = 7;
		}
		if (g_received == 2)
		{
			i--;
		}
	}
}

static void	process_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		process_char(pid, message[i]);
		i++;
	}
	process_char(pid, '\n');
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !is_int(argv[1]))
	{
		ft_putstr_fd("Usage: ./client [int=server PID] [message]\n", 2);
	}
	else
	{
		signal(SIGUSR1, process_received);
		signal(SIGUSR2, process_received);
		process_message((int)ft_atol(argv[1]), argv[2]);
	}
	return (0);
}
