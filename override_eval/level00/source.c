#include <stdio.h>
#include <stdlib.h>

// gcc -m32 -fno-stack-protector /tmp/level00.c -o /tmp/level00

int main(void)
{
	int	input;

	printf("***********************************\n");
	printf("* \t     -Level00 -\t\t  *\n");
	printf("***********************************\n");
	printf("Password:");
	scanf("%d", &input);
	if (input == 0x149c)
	{
		printf("\nAuthenticated!\n");
		system("/bin/sh");
	}
	else
	{
		printf("\nInvalid Password!\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
