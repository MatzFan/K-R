#include <stdio.h>

#define BUFSIZE   100 // buffer shared by getch() & ungetch

static char buf[BUFSIZE]; // buffer for ungetch
static int bufposition = 0;

int getch(void) // gets a (possibly pushed back) character from stdin
{
  return (bufposition > 0) ? buf[--bufposition] : getchar();
}

void ungetch(int c)
{
  if(bufposition >= BUFSIZE)
    printf("Error: ungetch has too many characters\n");
  else if(c != EOF) // ignore EOF
    buf[bufposition++] = c;
}
