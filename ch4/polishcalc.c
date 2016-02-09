#include <stdio.h>
#include <stdlib.h> // for atof()

#define MAXOP 100
#define NUMBER '0' // 48 in ASCII, could use any digit that can be part of a number

int getop(char []); // gets operators & operands
void push(double);
double pop(void);

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

/*---------------------------------------------------------------------*/

#define MAXVAL  100 // max value stack depth

int position = 0; // stack position *GLOBAL*
double val[MAXVAL]; // value stack *GLOBAL*

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

#include <ctype.h>

int getch(void); // getc is defined in stdlib.h
void ungetch(int); // ungetc is defined in stdlib.h

int getop(char s[])
{
    #define PERIOD  '.'
    int i = 0;
    int c;
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



#define BUFSIZE   100 // buffer shared by getch() & ungetch

char buf[BUFSIZE]; // buffer for ungetch
int bufposition = 0;

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





