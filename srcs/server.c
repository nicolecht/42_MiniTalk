#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "minitalk.h"

static void	server_sighandler(int sig, siginfo_t *info, void *ucontext)
{
	static int	c; // 0000 0000
	static int	bit_count;
	static int	client_pid;

	(void)ucontext;
	client_pid = info->si_pid; /* Sending process ID */
	if (sig == SIGUSR1)
		c += 1;
	if (++bit_count == 8)
	{
		bit_count = 0;
		if (!c) // if c equals null, send signal back as response to client
		{
			kill(client_pid, SIGUSR1);
			write(1, "\n", 1);
		}
		write(1, &c, 1);
		c = 0;
	}
	else 
		c <<= 1;
}

int main(void)
{
	 struct sigaction	act; // struct named sigaction with variable act

	act.sa_sigaction = server_sighandler; // access sa_sigaction of var act using member operator "."
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("Server PID: %d\n", getpid()); /* change to ft_printf */
	while (1)
		pause();	
}

