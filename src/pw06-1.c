#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // 16

    char c = '0';

    unsigned int count = 0;

    while ((c = getchar()) != '#')
    {
        if (isprint(c)) count++;
    }

    printf("char count: %u\n", count);

    return 0;
}