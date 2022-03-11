#include <stdio.h>

void decrypt(int input)
{

    char buf[17] = "Q}|u`sfg~sf{}|a3";

    size_t len = strlen(buf); /* ebp-0x24 */

    int i = 0; /* ebp-0x28 */
    while (i < len)
    {

        buf[i] = buf[i] ^ input;
        i++;
    }
    if (strncmp(buf, "Congratulations!", 17) == 0)
    {
        system("/bin/sh");
    } else {
        puts("\nInvalid Password");
    }
    return;
}

void test(int input, int nb)
{
    nb = nb - input;
    if (nb <= 21)
    {
        decrypt(nb);
        return;
    }
    decrypt(rand());
    return;
}


int main(int argc, char **argv) {

    int input; /* esp+0x1c */

    srand(time(0));
    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &input);
    test(input, 322424845);
    return 0;
}
