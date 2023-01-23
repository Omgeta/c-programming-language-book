#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int lim);
void squeeze(char s1[], const char s2[]);

int main() {
    char line[MAXLINE];
    char filter[MAXLINE];

    getline(line, MAXLINE);
    getline(filter, MAXLINE);
    squeeze(line, filter);
    printf("%s\n", line);

    return 0;
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i] = '\0';

    return i;
}

void squeeze(char s1[], const char s2[]) {
    int i, j, k;

    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}