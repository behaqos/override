
int main(void)
{
	int i = 0;
	char buf[100];

	fgets(buf, 100, stdin);
	for (i = 0; i < strlen(buf); i++)
		if (buf[i] >= 'A' && buf[i] <= 'Z')
			buf[i] ^= 0x20;
	printf(buf);
	exit(EXIT_SUCCESS);
	return EXIT_FAILURE;
}
