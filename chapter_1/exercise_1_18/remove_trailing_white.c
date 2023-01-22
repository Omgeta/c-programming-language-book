#include <stdio.h>

#define MAXLINE 1000  // maximum length of lines to save

int getline(char s[], int maxline);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        printf("%s", line);
    }
}

/* getline: read a line into s, remove its trailing whitespace, and return its length */
int getline(char s[], int lim) {
    int i, c;
    int whitespace = 0;  // white space counter

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        if (c == ' ' || c == '\t') {
            whitespace++;
        } else {
            whitespace = 0;
        }
        s[i] = c;
    }
    if (whitespace > 0) {
        i -= whitespace;
    }
    if (c == '\n') {
        if (i > 0) {
            s[i] = c;
            i++;
        }
    }
    s[i] = '\0';

    return i;
}