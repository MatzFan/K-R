#include <stdio.h>

int main()
{
	double nc = 0;

	while (getchar() != EOF)
		++nc; // sums number of input characters, including "\n"s
	printf("\n%.0f\n", nc); // add newline BEFORE to avoid overprinting ^D!
}
