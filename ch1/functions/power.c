#include <stdio.h>

/* As expected, params and local variables scope is within the function declaring them */

int power(int base, int n); // function prototype - param names & types OPTIONAL -> warn

int main()
{
    for(int i = 0; i < 10; ++i)
        printf("%d %6d %8d\n", i, power(2, i), power(-3, i));
    return 0;
}

int power(int base, int n) // types optional in func. def. - assume int's
{
    int p = 1;

    for(p = 1; n > 0; --n) // increment n to avoid declaring separate iterator :)
        p *= base;
    return p;
}
