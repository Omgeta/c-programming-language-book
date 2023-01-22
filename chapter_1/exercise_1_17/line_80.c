#include <stdio.h>

#define MINLEN 80     // minimum length of lines to print
#define MAXLINE 1000  // maximum length of lines to save

int getline(char s[], int maxline);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > MINLEN) {
            printf("%s", line);
        }
    }
}

/* getline: read a line into s, and return its length */
int getline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    while (c != EOF && c != '\n') {
        i++;
        c = getchar();
    }

    return i;
}