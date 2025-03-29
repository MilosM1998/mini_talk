#include "mini_talk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void take_msg(int sig, siginfo_t *info, void *context)
{
    static char c = 0;
    static int i = 0;

    (void)context; // Da izbegnemo warning

    c <<= 1;
    if (sig == SIGUSR2)
        c |= 1;
    i++;

    if (i == 8)
    {
        ft_putchar_fd(c, 1);
        if (c == '\0')
            ft_putchar_fd('\n', 1);
        i = 0;
        c = 0;
    }

    // Šaljemo potvrdu klijentu da smo primili bit
    kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;
    char *pid_str;

    pid_str = ft_itoa(getpid());
    ft_putstr_fd("Server PID is: ", 1);
    ft_putstr_fd(pid_str, 1);
    ft_putchar_fd('\n', 1);
    free(pid_str);

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO; // Omogućava pristup info o pošiljaocu
    sa.sa_sigaction = take_msg;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();
    
    return (0);
}
