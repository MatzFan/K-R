#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

void reverse_in_place(char s[]);
void characterize(int n, char s[]);

int main()
{
	printf("INT_MIN is %d\n", INT_MIN);
	char string[12]; // number of characters needed + 1 for '\0'
	characterize(INT_MIN, string); // INT_MIN
	printf("%s\n", string);
	return 0;
}

void reverse_in_place(char s[])
{
	int c, i, j;

	for(i = 0, j = strlen(s) -1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

/* fills the char[] param with characters representing the digits of param n */

void characterize(int n, char s[])
{
	int i, sign;

	if((sign = n) < 0)
		n = -n;
	i = 0;

	do {
		s[i++] = abs(n % 10) + '0'; // add int representing 0 to get int representing the digit :)
	} while(n /= 10); // see K&R solutions for why this isn't (n/=10) > 0 and abs used above
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse_in_place(s);
}
