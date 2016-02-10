#include <stdio.h>
#include "calc.h"

#define MAXVAL  100 // max value stack depth

static int position = 0; // stack position *GLOBAL*
static double val[MAXVAL]; // value stack *GLOBAL*

void push(double f)
{
  if(position < MAXVAL)
    val[position++] = f;
  else
    printf("Error: stack full, can't push %g\n", f);
}

double pop(void)
{
  if(position > 0)
     return val[--position];
  else
    printf("Error: stack empty\n");
    return 0.0;
}
