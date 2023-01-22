#include <stdio.h>

int main() {
    int b = 0, t = 0, nl = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++b;
        else if (c == '\t')
            ++t;
        else if (c == '\n')
            ++nl;
    }

    printf("Blanks: %d\nTabs: %d\nNew Lines: %d\n", b, t, nl);

    return 0;
}