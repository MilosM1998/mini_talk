/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:47:31 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/04 19:50:01 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

volatile sig_atomic_t	sig_received = 0;

void	handle_sig(int sig)
{
	(void)sig;
	sig_received = 1;
}

static int	check_pid(char *pid)
{
	while (*pid)
	{
		if (!ft_isdigit(*pid))
		{
			if (*pid == '-')
			{
				ft_putendl_fd("Error: Invalid PID.", 2);
				return (1);
				break ;
			}
			ft_putendl_fd("Error: PID should contain just a numbers!", 2);
			return (1);
			break ;
		}
		pid++;
	}
	return (0);
}

static void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		sig_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!sig_received)
			usleep(50);
		i--;
	}
}
static void	send_msg(pid_t pid, char *msg)
{
	while (*msg)
	{
		send_char(pid, *msg);
		msg++;
	}
	send_char(pid, '\0');
}
int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	if (ac != 3)
	{
		ft_printf("Usage: ./client <pid> <msg>");
		return (1);
	}
	if (check_pid(av[1]))
		return (1);
	pid = (pid_t)ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putendl_fd("Error: Invalid pid.", 2);
		return (1);
	}
	sa.sa_handler = handle_sig;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	send_msg(pid, av[2]);
	return (0);
}
