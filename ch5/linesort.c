#include <stdio.h>
#include <string.h>
#include "qsort.h"

#define MAXLINES  5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

// void qsort(char *lineptr[], int left, int right);

int main()
{
	int nlines;

	if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort_(lineptr, 0, nlines - 1);
		printf("\n");
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input exceeds limit of %d lines\n", MAXLINES);
		return 1;
	}
}

#define	MAXLEN	1000 // scope from here down

int getaline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while((len = getaline(line, MAXLEN)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len -1] = '\0'; // delete the newline '\n'
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;

	for(i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
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

#define ALLOCSIZE	10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) // p101
{
	if(allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n; // old p
	} else // not enough room in buffer
		return 0;
}
