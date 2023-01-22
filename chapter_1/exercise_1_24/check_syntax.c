#include <stdbool.h>
#include <stdio.h>

#define MAXSTR 10000

int getstr(char s[], int lim);
void check_syntax(char s[]);

int main() {
    char str[MAXSTR];

    getstr(str, MAXSTR);
    check_syntax(str);

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

void check_syntax(char s[]) {
    /*

    ()
    []
    {}
    /*
    '
    "

    */

    int parentheses = 0, brackets = 0, braces = 0;
    bool in_comment = false;
    bool single_quotes = false, double_quotes = false;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!in_comment && !single_quotes && !double_quotes) {
            switch (s[i]) {
                case '(':
                    parentheses++;
                    break;
                case ')':
                    parentheses--;
                    break;
                case '[':
                    brackets++;
                    break;
                case ']':
                    brackets--;
                    break;
                case '{':
                    braces++;
                    break;
                case '}':
                    braces--;
                    break;
            }
        }

        if (!in_comment) {
            if (s[i] == '\'' && !single_quotes && !double_quotes)
                single_quotes = true;
            else if (s[i] == '\'' && single_quotes && (s[i - 1] != '\\' || s[i - 2] == '\\'))
                single_quotes = false;

            else if (s[i] == '"' && !single_quotes && !double_quotes)
                double_quotes = true;
            else if (s[i] == '"' && single_quotes && (s[i - 1] != '\\' || s[i - 2] == '\\'))
                double_quotes = false;
        }

        if (!single_quotes && !double_quotes) {
            if (s[i] == '/' && s[i + 1] == '*')
                in_comment = true;
            else if (s[i] == '*' && s[i + 1] == '/')
                in_comment = false;
        }
    }

    if (parentheses) puts("Unbalanced parentheses.");
    if (brackets) puts("Unbalanced brackets.");
    if (braces) puts("Unbalanced braces.");
    if (single_quotes) puts("Unbalanced single quotes.");
    if (double_quotes) puts("Unbalanced double quotes.");
    if (in_comment) puts("Unclosed comment.");
}