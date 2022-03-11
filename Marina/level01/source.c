#include <stdio.h>
char a_user_name[100];				// 0x64 - 100 ; 0x804a040


int	verify_user_name(void)
{
	char *real_uname = "dat_wil";			// 0x80486a8
	puts("verifying username....\n");
	return (strcmp(real_uname, a_user_name));
}

int	verify_user_pass(char *buff)
{
	char *real_passw = "admin";			// 0x80486b0
	return (strcmp(real_passw, buff));
}


int	main(void)
{
	char	buff[64] = {0};			// [esp+0x1c] +11 - +29 0x5c - 0x1c
	int	n = 0;				// [esp+0x5c]

	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 0x100, stdin);
	n = verify_user_name();
	if (n != 0)
	{
		puts("nope, incorrect username...\n");
		return (1);
	}
	puts("Enter Password: ");
	// ОПЕЧАТКА! контролирует 100 байт вместо 64 - залезаем на чужую память
	// значит, можем перезаписать нужные байты
	fgets(buff, 0x64, stdin);
	verify_user_pass(buff);
	puts("nope, incorrect password...\n");
	return (1);
}
