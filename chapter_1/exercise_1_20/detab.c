#include <stdio.h>

#define TAB_LENGTH 8

int main() {
    int c;
    unsigned int i = 0;
    unsigned int remaining_spaces;

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            remaining_spaces = TAB_LENGTH - (i % TAB_LENGTH);
            i += remaining_spaces - 1;
            while (remaining_spaces--) {
                putchar(' ');
            }
        } else {
            if (c == '\n')
                i = 0;
            putchar(c);
        }
        i++;
    }

    return 0;
}