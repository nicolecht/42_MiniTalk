#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

int	ft_strisdigit(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{

		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	feedback(int sig)
{
	(void)sig;
	ft_printf("SUCCESS: String received by server\n");
	exit (0);
}

void	client_sighandler(int pid, char *string)
{
	int	bit_count;
	int	byte_count;
	char c;

	byte_count = 0;
	while (string[byte_count] - 1)
	{
		c = string[byte_count];
		bit_count = 8;
		while (--bit_count >= 0)
		{
			if (c && ((c >> bit_count) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(60);
		}
		byte_count++;
	}
}

int main (int argc, char **argv)
{
	signal(SIGUSR1, feedback);
	if (argc != 3 || !ft_strisdigit(argv[1]) || !*argv[2])
	{
		ft_printf("ERROR: Wrong Format\n");
		ft_printf("TRY: ./client <PID Number> <String>");
	}
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

// bit-shifting
// loop starts by shifting the first left bit to the end (i = 7)
// then compare with & 1 
// if it's 1 return 1 , if its 0 return 0
// kill signal is sent starting with first left bit to final 8th bit
// (following the bits order)
//
// the 8 bits is calculated by the number of 2 powered number of shifts)
// num = 2 ^ num of shifts
// W : ascii 87 = 64 + 16 + 4 + 2 + 1 
// the successful numbers above represents 1 , if not then 0
// ex: 2^7 = 128 = 0 | 2^6 = 64 = 1 | 2^5 = 32 = 0
// https://www.binaryhexconverter.com/ascii-text-to-binary-converter
// decimal numbers is opposite using number equals 1 over (2 power number of shifts)