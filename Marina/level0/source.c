#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int value;

	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");
	printf("Password:");
	scanf("%d", value);
	if (value ==  0x149c)
	{
		puts("\nAuthenticated!");
		system("/bin/sh");
	}
	puts("\nInvalid Password!");
	