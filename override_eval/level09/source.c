#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -pie -fPIE -fno-stack-protector /tmp/level09.c -o /tmp/level09

struct savestate {
	char msg[140];
	char username[40];
	int msglen;
} save;

void set_msg(struct savestate *save);
void set_username(struct savestate *save);

void secret_backdoor(void)
{
	char cmd[128];

	fgets(cmd, sizeof(cmd), stdin);
	system(cmd);
}

void handle_msg(void)
{
	struct savestate save;

	memset(save.username, 0, sizeof(save.username));
	save.msglen = 140;
	set_username(&save);
	set_msg(&save);
	printf(">: Msg sent!\n");
}

void set_msg(struct savestate *save)
{
	char readbuf[1024];

	memset(readbuf, 0, sizeof(readbuf));
	printf(">: Msg @Unix-Dude\n");
	printf(">>: ");
	fgets(readbuf, sizeof(readbuf), stdin);
	strncpy(save->msg, readbuf, save->msglen);
}

void set_username(struct savestate *save)
{
	int i;
	char readbuf[128];

	memset(readbuf, 0, sizeof(readbuf));
	printf(">: Enter your username\n");
	printf(">>: ");
	fgets(readbuf, sizeof(readbuf), stdin);
	for (i = 0; i <= 40 && readbuf[i]; i++)
		save->username[i] = readbuf[i];
	printf(">: Welcome, %s", save->username);
}

int main(void)
{
	printf("--------------------------------------------\n" \
	       "|   ~Welcome to l33t-m$n ~    v1337        |\n" \
	       "--------------------------------------------\n");
	handle_msg();
	return EXIT_SUCCESS;
}
