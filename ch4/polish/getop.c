#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* changes s[] IN PLACE to a strign represenastion of a float */
/* returns either NUMBER if s[] contains a number */
char getop(char s[])
{
    #define PERIOD  '.'
    int i = 0;
    char c;
    int next;

    while((s[0] = c = getch()) == ' ' || c == '\t') // skip leading whitespace
        ;
    s[1] = '\0';

    if(!isdigit(c) && c != PERIOD && c != '-') // could be unary minus
        return c;

    if(c == '-') {
        next = getch();
        if(!isdigit(next) && next != PERIOD) {// c must be binary operator '-'
           return c;
        }
        c = next; // must now be a digit or period
    }
    else {
        c = getch();
    }

    while(isdigit(s[++i] = c))
            c = getch();
    if(c == PERIOD)
        while(isdigit(s[++i] = c = getch())) // get fractional part
                        ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}
