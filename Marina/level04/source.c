#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <sys/reg.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	pid_t	child; //esp+0xac
	int		status;	//esp+0x1c
	char	str[32]; // esp+0x20
	int		c; //esp+0xa0
	int		d; //esp+0xa4
	int		b; //esp+0xa8

	child = fork(); // создает дочерний поток
	memset(str, 0, 32);
	b = 0;
	status = 0;
	if (child == 0)
	{
			prctl(PR_SET_PDEATHSIG, SIGHUP); // убить дочерний поток вместе с родительским
			ptrace(PTRACE_TRACEME, 0, 0, 0); .//
			puts("Give me some shellcode, k"); // нужна перезапись регистра
			gets(str);// используем для переполнения и перезаписи
	}
	else
	{
		while (b != 11)
		{
			wait(status);
			c = status;
			if (__WTERMSIG(status) != 0)
			{
				d = status
				if (__WIFSIGNALED(d) > 0)
				{
					b = ptrace(PTRACE_PEEKUSER, child, ORIG_EAX * 4, 0);
					if (b == 11)
					{
						puts("no exec() for you");
						kill(child);
						break;
					}
					else
						continue;
				}
			}
			puts("child is exiting...");
			break;
		}
	}
	return (0);
}
