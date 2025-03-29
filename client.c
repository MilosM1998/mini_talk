#include "mini_talk.h"
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t ack_received = 0;

void handle_ack(int sig)
{
    (void)sig;
    ack_received = 1;
}

static int	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
		{
			if (pid[i] == '-')
			{
				ft_putendl_fd("Error: Invalid pid.", 2);
				return (1);
				exit(1);
			}
			ft_putendl_fd("Error: Pid should contain just numbers.", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
void send_char(pid_t pid, char c)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        ack_received = 0;  // Resetujemo pre slanja bita

        if ((c >> i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);

        // Čekamo da server potvrdi prijem bita
        while (!ack_received)
            usleep(50);

        i--;
    }
}

void send_msg(pid_t pid, char *str)
{
    while (*str)
    {
        send_char(pid, *str);
        str++;
    }
    send_char(pid, '\0'); // Šaljemo završni karakter
}

int main(int ac, char **av)
{
    pid_t pid;
    struct sigaction sa;

    if (ac != 3)
    {
        ft_putendl_fd("Usage: ./client <PID> <MSG> ", 2);
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

    // Postavljanje handlera za primanje SIGUSR1 (ack)
    sa.sa_handler = handle_ack;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    send_msg(pid, av[2]);

    return (0);
}
