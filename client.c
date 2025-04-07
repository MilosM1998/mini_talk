/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:47:31 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/07 21:08:09 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

volatile sig_atomic_t	g_sig_received = 0;

void	handle_sig(int sig)
{
	(void)sig;
	g_sig_received = 1;
}

static void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_sig_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_sig_received)
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
	struct sigaction	siga;

	if (ac != 3)
	{
		ft_printf("Usage: ./client <pid> <msg>");
		return (1);
	}
	if (check_pid(av[1]))
		return (1);
	pid = (pid_t)ft_atoi(av[1]);
	if (pid_exist_check(pid))
		return (1);
	siga.sa_handler = handle_sig;
	siga.sa_flags = 0;
	sigemptyset(&siga.sa_mask);
	sigaction(SIGUSR1, &siga, NULL);
	send_msg(pid, av[2]);
	return (0);
}
