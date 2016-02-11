#include <string.h>

/* pointer implementation of recursive quicksort algorithm */

void qsort_(char *v[], int left, int right);
void swapit(char *v[], int i, int j);

void qsort_(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if(left >= right)
		return;
	swapit(v, left, (left + right)/2);
	last = left;
	for(i = left + 1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swapit(v, ++last, i);
	swapit(v, left, last);
	qsort_(v, left, last - 1);
	qsort_(v, last + 1, right);
}

void swapit(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
