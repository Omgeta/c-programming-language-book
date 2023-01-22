#include <stdio.h>

#define TAB_LENGTH 8

int main(void) {
    int c;
    unsigned int i = 0;
    unsigned int num_spaces = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++num_spaces;

            if (i % TAB_LENGTH == 0) {
                putchar('\t');
                num_spaces = 0;
            }
        } else {
            while (num_spaces) {
                putchar(' ');
                --num_spaces;
            }

            if (c == '\n')
                i = 0;

            putchar(c);
        }
        i++;
    }

    return 0;
}
