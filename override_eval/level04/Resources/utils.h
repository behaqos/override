#define deathrays \
    __asm__ volatile("push     %eax      \n" \
                     "xor      %eax, %eax\n" \
                     "je       .+5       \n" \
                     "add      $0x4,%esp \n" \
                     "pop      %eax      \n");

#define clear_argv(_argv) \
    while (*_argv) \
    { \
        memset(*_argv, '\0', strlen(*_argv)); \
        _argv++; \
    }
#define clear_envp(_envp) clear_argv(_envp)

#include <stdbool.h>
void clear_stdin(void)
{
    char x = 0;

    while (true)
    {
        x = getchar();
        if (x == '\n' || x == EOF)
            break;
    }
}

unsigned int get_unum(void)
{
    unsigned int res = 0;

    fflush(stdout);
    scanf("%u", &res);
    clear_stdin();
    return res;
}

void prog_timeout(int sig)
{
  asm("mov $1, %eax;"
      "mov $1, %ebx;"
      "int $0x80");
}

#include <signal.h>
#define ENABLE_TIMEOUT(_time) \
    { \
        signal(SIGALRM, prog_timeout); \
        alarm(_time); \
    }
