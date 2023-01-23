#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char s[], int lim);
int htoi(const char h[]);

int main() {
    char hex_str[MAXLINE];

    int len = getline(hex_str, MAXLINE);

    printf("%s = %d\n", hex_str, htoi(hex_str));

    return 0;
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i] = '\0';

    return i;
}

int htoi(const char h[]) {  // fff or 0xfff or 0XFFF
    int result = 0;
    int len = strlen(h);
    bool valid_digit;

    for (int i = 0; i < len; i++) {
        valid_digit = false;

        if (h[i] == '0' && (h[i + 1] == 'x' || h[i + 1] == 'X'))
            i += 2;

        int temp = tolower(h[i]);

        // converting hex digits to integer values
        if (isdigit(temp)) {
            temp -= '0';
            valid_digit = true;
        } else if (temp >= 'a' && temp <= 'f') {
            temp = temp - 'a' + 10;
            valid_digit = true;
        }

        // adding to final result
        if (valid_digit) {
            result += temp * (int)pow(16, len - i - 1);
        } else {
            printf("Error: invalid hex digit %c.\n", h[i]);
        }
    }

    return result;
}