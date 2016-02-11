#include <stdio.h>
#include <string.h>
#include "qsort.h"

#define MAXLINES  500
#define MAXSTORE  10000// storage for all lines

char *lineptr[MAXLINES]; // POINTER TO EACH TEXT LINE

int readlines(char *lineptr[], int nlines, char linestore[]);
void writelines(char *lineptr[], int nlines);

int main()
{
	int nlines;
	char linestore[MAXSTORE];

	if((nlines = readlines(lineptr, MAXLINES, linestore)) >= 0) {
		qsort_(lineptr, 0, nlines - 1);
		printf("\n");
		writelines(lineptr, nlines);
		return 0;
	}
	else
		return 1;
}

#define	MAXLEN	1000 // scope from here down

int getaline(char *, int);
// char *alloc(int);

int readlines(char *lineptr[], int maxlines, char *ls)
{
	int len, nlines;
	char *p; // p is pointer to ls - the array defining max storage for all lines
	char line[MAXLEN];
	nlines = 0;
	p = ls + strlen(ls); // first call initializes p to address of ls[0], as ls has zero length
	while((len = getaline(line, MAXLEN)) > 0) // len is the line length
		if((strlen(ls) + len) > MAXSTORE) {
        	printf("error: input exceeds line storage of %d characters\n", MAXSTORE);
        	return 1;
        }
		else if(nlines >= maxlines) {
			printf("error: input exceeds limit of %d lines\n", MAXLINES);
        	return 1;
		} else {
			line[len -1] = '\0'; // delete the newline '\n'
			strcpy(p, line); // BECAUSE p POINTS TO ADDRESS IN ls[0], THIS COPIES EACH LINE IN TURN INTO ls
			lineptr[nlines++] = p;
			p += len; // increment p to next free postion
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;

	while(nlines-- > 0) // de-increment nlines while there is a line
		printf("%s\n", *lineptr++); // increment array pointer & print char[] at that address
}

int getaline(char s[], int lim) // returns line length from stdin input
{
	int c, i;

	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n') // i.e. not EOF
		s[i++] = c;
	s[i] = '\0'; // always add null character!!
	return i;
}

// #define ALLOCSIZE	10000

// static char allocbuf[ALLOCSIZE];
// static char *allocp = allocbuf;

// char *alloc(int n) // p101
// {
// 	if(allocbuf + ALLOCSIZE - allocp >= n) {
// 		allocp += n;
// 		return allocp - n; // old p
// 	} else // not enough room in buffer
// 		return 0;
// }
