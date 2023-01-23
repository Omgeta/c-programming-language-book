#include <stdio.h>

int any(const char s1[], const char s2[]);

int main() {
    char str[] = "Hello, world!";
    char substr1[] = "ol";
    char substr2[] = "abc";

    printf("Location of \"%s\" in \"%s\": %d\n", substr1, str, any(str, substr1));
    printf("Location of \"%s\" in \"%s\": %d\n", substr2, str, any(str, substr2));

    return 0;
}

int any(const char s1[], const char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;

    return -1;
}