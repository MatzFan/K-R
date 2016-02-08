#include <stdio.h>
#include <string.h>

void reverse_in_place(char s[]);
void characterize(int n, char s[]);

int main()
{
    char string[4];
    characterize(-234, string);
    printf("%s\n", string);
    return 0;
}

void reverse_in_place(char s[])
{
    int c, i, j;

    for(i = 0, j = strlen(s) -1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

/* fills the char[] param with characters representing the digits of param n */

void characterize(int n, char s[])
{
    int i, sign;

    if((sign = n) < 0)
        n = -n;
    i = 0;

    do {
        s[i++] = n % 10 + '0'; // add int representing 0 to get int representing the digit :)
    } while((n /= 10) > 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse_in_place(s);
}
