#import <stdio.h>

#define MAXLINE 1000

int linelength(char line[], int maxline); // function prototype
void copy(char to[], char from[]); // function prototype

int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while((len = linelength(line, MAXLINE)) > 0) // 0 works as EOF as line cannot be 0 length
        if(len > max) {
            max = len;
            copy(longest, line); // store longest line
        }
    if(max > 0) // zero output if no input :)
        printf("\n%d %s", max, longest); // %s MUST FIND '\n' at end of array
    return 0;
}

int linelength(char s[], int lim)
{
    int i, c;

    for(i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i) // check line isn't over lim length
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    // s[i] = '\0'; // WORKS FINE WITHOUT THIS????
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
