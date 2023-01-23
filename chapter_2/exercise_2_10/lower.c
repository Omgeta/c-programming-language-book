#include <ctype.h>
#include <stdio.h>

const char lower(const char c);

int main() {
    char a = 'D';
    putchar(lower(a));

    return 0;
}

const char lower(const char c) {
    return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}