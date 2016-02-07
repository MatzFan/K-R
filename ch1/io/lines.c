#include <stdio.h>

/* counts blanks tabs and newlines */

int main()
{
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF)
        if(c == '\n' || c == '\t' || c == ' ') // '\n' is a character constant (ASCII 10)
                                               // "\n" is a STRING constant - NOT an int!!
            ++nl;
    printf("\n%d\n", nl);
}
