#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void	main()
{
	char buf[100];
	int i;

	fgets(buf, 100, stdin);
	i = 0;
	if (strlen(buf) > 0)
	{
		while (i < strlen(buf))
		{
			tolower(buf[i]);
			i++;
		}
	}
	printf(buf);//можем изменить конкретный адрес
	exit(0);
}
