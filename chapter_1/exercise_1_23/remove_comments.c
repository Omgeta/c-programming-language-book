#include <stdbool.h>
#include <stdio.h>

#define MAXSTR 10000

int getstr(char s[], int lim);
void remove_comments(char s[], char no_com[]);

int main() {
    char str[MAXSTR];
    char no_com_str[MAXSTR];

    getstr(str, MAXSTR);
    remove_comments(str, no_com_str);
    printf("%s", no_com_str);

    return 0;
}

int getstr(char s[], int lim) {
    int c;
    int i = 0;

    while ((c = getchar()) != EOF && i < lim - 1) {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

void remove_comments(char s[], char no_com[]) {
    bool in_quote = false;
    bool in_comment = false;

    int i = 0, j = 0;
    while (s[i] != '\0') {
        if (!in_comment && s[i] == '"') {
            if (!in_quote)
                in_quote = true;
            else if (in_quote)
                in_quote = false;
        }

        if (!in_quote) {
            if (s[i] == '/' && s[i + 1] == '*')
                in_comment = true;
            else if (s[i] == '*' && s[i + 1] == "/") {
                in_comment = false;
                i += 2;
            }

            if (in_comment)
                i++;
            else {
                no_com[j++] = s[i++];
            }
        } else {
            no_com[j++] = s[i++];
        }
    }
    no_com[j] = '\0';
}