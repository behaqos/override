#include <sys/ptrace.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_GREEN  "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"

// gcc -m32 /tmp/level06.c -o /tmp/level06

ENABLE_TIMEOUT(60)

int auth(char *username, unsigned int serial)
{
	int i, len;
	unsigned int chk;

	username[strcspn(username, "\n")] = '\0';
	len = strnlen(username, 32);
	if (len < 6)
		return 1;
	if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
	{
		printf(ANSI_COLOR_GREEN ".---------------------------.\n");
		printf(ANSI_COLOR_RED   "| !! TAMPERING DETECTED !!  |\n");
		printf(ANSI_COLOR_GREEN "'---------------------------'\n");
		return 1;
	}
	chk = (username[3] ^ 0x1337) + 0x5EEDED;
	for (i = 0; i < len; i++)
	{
		if (username[i] < 32 || username[i] > 127)
			return 1;
		chk += (username[i] ^ chk) % 1337;
	}
	if (serial != chk)
		return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	unsigned int serial;
	char username[32];

	deathrays;
	printf("***********************************\n");
	printf("*\t\tlevel06\t\t  *\n");
	printf("***********************************\n");
	printf("-> Enter Login: ");
	fgets(username, 32, stdin);
	printf("***********************************\n");
	printf("***** NEW ACCOUNT DETECTED ********\n");
	printf("***********************************\n");
	printf("-> Enter Serial: ");
	scanf("%u", &serial);
	if (!auth(username, serial))
	{
		printf("Authenticated!\n");
		system("/bin/sh");
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
