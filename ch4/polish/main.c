#include <stdio.h>
#include <stdlib.h> // for atof()
#include "calc.h"

#define MAXOP 100

int main()
{
  int type;
  double temp;
  char s[MAXOP];

  while((type = getop(s)) != EOF) { // getop changes s IN PLACE
    switch(type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      temp = pop(); //
      push(pop() - temp);
      break;
    case '/':
      temp = pop();
      if(temp != 0.0)
        push(pop() / temp);
      else
        printf("Error: zero division\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop()); // presumes there is something on the stack - could be empty if zero input..
      break;
    default:
      printf("Error: unknown command %s\n", s); // fallthrough
      break; // futureproof :)
    }
  }
  return 0;
}
