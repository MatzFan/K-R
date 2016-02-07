#import <stdio.h>

#define IN  1
#define OUT 2

/* count lines, words and characters in input - UNIX wc*/

int main()
{
    int c, nl, nw, nc, state;

    state = OUT; // records whether we are ina word or not
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("\n%d %d %d\n", nl, nw, nc);
}
