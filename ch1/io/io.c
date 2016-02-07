#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) // EOF for keyboard input is "ctrl D"
        putchar(c);

    return 0;
}
