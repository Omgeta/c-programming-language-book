#include <stdio.h>

#define MAXLINE 10000  // max line length to print
#define LINE_BREAK 10

int getline(char s[], int lim);
void fold_line(char fold_str[], char line[], int n_break);

int main() {
    int c, len;
    char line[MAXLINE];
    char fold_str[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        fold_line(fold_str, line, LINE_BREAK);
        printf("%s", fold_str);
    }

    return 0;
}

/* getline: read a line into s, and return its length */
int getline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

/* fold_line: split up a long line into different smaller lines without leading or trailing whitespace */
void fold_line(char fold_str[], char line[], int n_break) {
    int i, j;
    int column = 0;
    int last_blank = 0;

    for (i = 0, j = 0; line[i] != '\0'; i++, j++) {
        fold_str[j] = line[i];

        if (fold_str[j] == '\n')
            column = 0;

        column++;

        if (fold_str[j] == ' ' || fold_str[j] == '\t')
            last_blank = j;

        if (column == n_break) {
            if (last_blank) {
                fold_str[last_blank] = '\n';
                column = j - last_blank;
                last_blank = 0;
            } else {
                fold_str[++j] = '\n';
                column = 0;
            }
        }
    }

    fold_str[j] = '\0';
}