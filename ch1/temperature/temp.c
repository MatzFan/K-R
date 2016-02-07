#import <stdio.h>

/* prints Farenheit-Celsius table
    for fahr = 0, 20 ..., 300 */

#define LOWER   0
#define UPPER 300
#define STEP   20

int main()
{
    printf("Fahr\tCelsius\n");

    for(int fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
