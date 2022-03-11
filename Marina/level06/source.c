#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int	auth(char *login, unsigned int serial)
{
	int len; // ebp - 0xc
	int a;	// ebp - 0x10
	int i; // ebp - 0x14

	login[strcspn(login, "\n")] = 0;
	len = strnlen(login, 32);
	if (len > 5)
	{
		if (ptrace(0, 0, 1, 0) == -1) {
			puts("\033[32m.---------------------------."); 
			puts("\033[31m| !! TAMPERING DETECTED !!  |");
			puts("\033[32m'---------------------------'");
			return(1);
		}
		// тут должен быть подсчет хеш суммы но он что то больно сложный )
		if (serial == a)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argc)
{
	char login[32]; //esp + 0x2c
	unsigned int serial; //esp + 0x28

	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: "); 
	fgets(login, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", serial);
	if (auth(login, serial) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		return(0);
	}
	else
		return (1);
}
