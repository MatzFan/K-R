#import <stdio.h>
#import <stdlib.h>

int binsearch(int x, int v[], int len);

int main()
{
    int array[6] = {6,7,9,12,14,34};

    printf("%d\n", binsearch(14, array, sizeof(array)/sizeof(int)));
    return 0;
}

/* returns index of x in array v[] - or -1 if not found */

int binsearch(int x, int v[], int len)
{
    int low, high, index;

    low = 0;
    high = len - 1;
    index = (low + high) / 2;

    while(low <= high && x != v[index]) {
        if(x < v[index])
            high = index - 1;
        else if(x > v[index])
            low = index + 1;
        index = (low + high) / 2; // integer division truncates :)
    }
    if(x == v[index])
        return index; // found
    else
        return -1; // no match
}
