// rmb to add linebreak and error validation for wrong server pid input by client

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "minitalk.h"

static void	server_sighandler(int sig, siginfo_t *info, void *ucontext)
{
	static int	c;
	static int	bit_count = 0;
	static int	client_pid;

	(void)ucontext;
	client_pid = info->si_pid; /* Sending process ID */
	// if (sig == SIGUSR1)
	// 	c += 1;
	// if (++bit_count == 8)
	// {
	// 	bit_count = 0;
	// 	if (!c)
	// 		kill(client_pid, SIGUSR1);
	// 	write(1, &c, 1);
	// 	c = 0;
	// }
	// else 
	// 	c <<= 1;
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

// sigaction structure
// struct sigaction {
//                void     (*sa_handler)(int);
//                void     (*sa_sigaction)(int, siginfo_t *, void *);
//                sigset_t   sa_mask;
//                int        sa_flags;
//                void     (*sa_restorer)(void);
//            };

// IF SA_SIGINFO is specified in sa_flags,
// then sa_sigaction (instead of sa_handler) specifies the signal handling function for signum
// this function receives 3 arguments to establish a signal handler
// sa_handler only takes 1 argc

// sa_flags specifies set of flags which modify the behavior of the signal
// It is formed by the bitwise "OR of zero" or by SA_SIGINFO
//
// When SA_SIGINFO flag is specified in act.sa_flags,
// signal handler address is passed via act.sa_sigaction
// void handler (int sig, siginfo_t *info, void *ucontext)
// sig = signum that invocated the handler
// info = pointer to siginfo_t, which is a structure containing info about the signal
// ucontext = pointer to ucontext_t structure, cast to void *
// 			= the handler function x make any use of this arg


// pause() - suspends program execution until a signal arrives
//			- whose action is either to execute a handler function or to terminate the process
//			- if signal causes handler function to be executed, then pause returns