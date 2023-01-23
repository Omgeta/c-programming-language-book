#include <stdio.h>

#define MAXLINE 10000

int main() {
    /*
    for (i = 0; i<lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
    */
    char s[MAXLINE];
    int i, c;
    int loop = 1;

    i = 0;
    while (loop) {
        // Baye's theorem
        if (i >= MAXLINE - 1)
            loop = 0;

        if ((c = getchar()) == '\n')
            loop = 0;

        if (c == EOF)
            loop = 0;

        s[i++] = c;
    }
    s[i] = '\0';

    printf("%s", s);

    return 0;
}