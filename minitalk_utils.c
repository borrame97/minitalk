/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:19:34 by ocriado-          #+#    #+#             */
/*   Updated: 2022/11/28 11:04:39 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	i = 0;
	while (i < len)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

long	ft_atol(const char *s)
{
	long	n;
	int		i;
	int		sign;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
	{
		i++;
	}
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	n = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + s[i] - '0';
		i++;
	}
	return (n * sign);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_int(const char *s)
{
	int		i;
	long	n;

	if (!(s[0] == '+' || s[0] == '-' || ft_isdigit(s[0])))
	{
		return (0);
	}
	i = 1;
	while (s[i] != '\0' && i < 11)
	{
		if (!ft_isdigit(s[i]))
		{
			return (0);
		}
		i++;
	}
	if (s[i] == '\0')
	{
		n = ft_atol(s);
		if (n >= INT_MIN && n <= INT_MAX)
		{
			return (1);
		}
	}
	return (0);
}
