/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:30:50 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/04 19:35:40 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mini_talk.h"

static void take_msg(int sig, siginfo_t *info, void *context)
{
    static int i = 0;
    static char c = 0;
    
    (void)context;
    c <<= 1;
    if(sig == SIGUSR2)
        c |= 1;
    i++;
    if(i == 8)
    {
        ft_printf("%c", c);
        if(c == '\0')
            ft_printf("\n");
        i = 0;
        c = 0;
    }
    kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction sa;
	int pid;

	pid = getpid();
	ft_printf("%d\n", pid);
    
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &take_msg;
	sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}