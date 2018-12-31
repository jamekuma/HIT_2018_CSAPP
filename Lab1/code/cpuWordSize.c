#include <stdio.h>

int cpuWordSize(void);

int main()
{
    printf("Cpu word size is %d bit\n", cpuWordSize());
}

int cpuWordSize(void)
{
    return (int)(8 * sizeof(char *));
}
