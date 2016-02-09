#include <stdio.h>

#define MAXLINE 1000

int getaline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found = 0;

	while(getaline(line, MAXLINE))
		if(strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found; // return to env number of matching lines found
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

int strindex(char s[], char t[]) // returns index of t[] in s[] or -1
{
	int i, j, k;

	for(i = 0; s[i] != '\0'; i++) { // iterate the string
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) // j indexes string, k indexes pattern
			;
		if(k > 0 && t[k] == '\0')
			return i;
	}
	return -1; // failed to find match on this line
}
