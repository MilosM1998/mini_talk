#include "mini_talk.h"

static int	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_putendl_fd("Pid should contain just numbers..", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

void	send_msg(pid_t server_pid, char *str)
{
	while (*str)
	{
		send_char(server_pid, *str);
		str++;
	}
	send_char(server_pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t	pid;

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
		ft_putendl_fd("Error invalid pid", 2);
		return (1);
	}
	send_msg(pid, av[2]);
}
