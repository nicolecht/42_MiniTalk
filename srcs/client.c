#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

void	feedback(int sig)
{
	(void)sig;
	write (1, "received", 8);
}

void	client_sighandler(int sig, char *message)
{
	printf("%d", sig);
	printf("%s", message);
}

int main (int argc, char **argv)
{
	signal(SIGUSR1, feedback);
	if (argc != 3)
		printf("invalid");
	else
		client_sighandler(ft_atoi(argv[1]), argv[2]);
}

// exit() - terminate a process or function calling immediately in the program
// sleep() - make the program wait for a short interval
// kill() - int kill (pid_t pid, int sig)
//			- a sys call to send signal to process group or process
//			- 
// SIGINT - predefined signal to terminate process
// signal - Small notifications sent between processes inside the kernel and the userspace
//			- aka software interrupts as they usually stop the normal execution of the program
//			- and execute the special action for the given signal type
//			- The actions are mostly defined as a default across the systems
//			- but users can implement a special function and register it as new action for the signal.
// signal handling - This process can ignore the signal, specify a handler function, or accept the default action for that signal
// sigaction()  - is a system call used to change the action taken by a process on receipt of a specific signal.
//				- register signal handlers
//				- uses struct sigaction arguments to specify the handler function pointer and other indicators
// signal() - signal(int sig, void *function (int))
//			- sets a function to handle signal i.e. a signal handler with signal number sig