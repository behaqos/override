#include <sys/reg.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include "utils.h"

// gcc -m32 -z execstack -fno-stack-protector /tmp/level04.c -o /tmp/level04

ENABLE_TIMEOUT(60)

int main(void)
{
	pid_t child = fork();
	char buffer[128] = {0};
	int syscall = 0;
	int status = 0;

	if (!child)
	{
		prctl(PR_SET_PDEATHSIG, SIGHUP);
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		puts("Give me some shellcode, k");
		gets(buffer);
	}
	else
	{
		while (true)
		{
			wait(&status);
			if (WIFEXITED(status) || WIFSIGNALED(status))
			{
				puts("child is exiting...");
				break;
			}
			syscall = ptrace(PTRACE_PEEKUSER, child, 4 * ORIG_EAX, NULL);
			if (syscall == 11)
			{
				printf("no exec() for you\n");
				kill(child, SIGKILL);
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}
