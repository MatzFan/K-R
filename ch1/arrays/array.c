#include <stdio.h>

#define NUM_DIGITS	10

/* histogram of digits, whitespace  & other count*/

int histo(n)
{
	int i;
	for(i = 0; i <= n; ++i)
		printf("*");

	return 0;
}

int main()
{
	int c, i, nwhite, nother;
	int ndigit[NUM_DIGITS]; // array size 10

	nwhite = nother = 0;
	for(i = 0; i < NUM_DIGITS; ++i)
		ndigit[i] = 0;

	while((c = getchar()) != EOF) // no braces required as each condition has a 1 line statement
		if(c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if(c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

		printf("digits\n");
		for(i = 0; i < NUM_DIGITS; i ++)
			histo(ndigit[i]);
		printf("\nwhite space\n");
			histo(nwhite);
		printf("\nother\n");
			histo(nother);
		printf("\n");

	return 0;
}
