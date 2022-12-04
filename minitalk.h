/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:33:20 by oscar             #+#    #+#             */
/*   Updated: 2022/11/28 10:33:21 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h> // write, getpid, usleep, pause
# include <limits.h> //	INT_MIN, INT_MAX
# include <signal.h> // signal, kill, sigaction

// minitalk_utils.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
long	ft_atol(const char *s);
int		is_int(const char *s);

#endif