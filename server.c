/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:30:50 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/07 21:08:35 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mini_talk.h"

static void	take_msg(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;

	(void)context;
	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			ft_printf("\n");
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	siga;
	int					pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	siga.sa_flags = SA_SIGINFO;
	siga.sa_sigaction = take_msg;
	sigemptyset(&siga.sa_mask);
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		pause();
	return (0);
}
