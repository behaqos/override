#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	FILE	*flag_file;
	int		flag_size;
	char	username[100] = {0};
	char	flag[42] = {0};
	char	password[112] = {0};

	flag_file = fopen("/home/users/level03/.pass", "r");
	if (!flag_file)
	{
		fwrite("ERROR: failed to open password file\n", 1, 36,stderr);
		exit(1);
	}
	flag_size = fread(flag, 1, 41, flag_file);
	flag[strcspn(flag, "\n")] = 0;
	if (flag_size != 41)
	{
		fwrite("ERROR: failed to read password file\n", 1, 36,stderr);
		fwrite("ERROR: failed to read password file\n", 1, 36,stderr);
		exit(1);
	}
	fclose(flag_file);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets(username, 100, stdin);
	username[strcspn(username, "\n")] = 0;
	printf("--[ Password: ");
	fgets(password, 100, stdin);
	password[strcspn(password, "\n")] = 0;
	puts("*****************************************");
	if (strncmp(flag, password, 41))
	{
		printf(username); // можем распечатать все содержимое программы и пароль в том числе
		puts("does not have access!");
		exit(1);
	}
	printf("Greetings, %s!\n", username);
	system("/bin/sh");
	return(0);
}
