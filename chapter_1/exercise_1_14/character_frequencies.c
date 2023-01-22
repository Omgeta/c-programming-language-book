#include <stdio.h>

#define ALPHA_NUM 26
#define DIGIT_NUM 10

int main() {
    int c;
    int char_histogram[ALPHA_NUM + DIGIT_NUM];

    for (size_t i = 0; i < (ALPHA_NUM + DIGIT_NUM); i++)
        char_histogram[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            char_histogram[c - '0']++;
        } else if (c >= 'a' && c <= 'z') {
            char_histogram[c - 'a' + DIGIT_NUM]++;
        }
    }

    printf("Histogram\n===================\n");
    for (size_t i = 0; i < (ALPHA_NUM + DIGIT_NUM); i++) {
        if (i < DIGIT_NUM) {
            printf("%c ", '0' + i);
        } else if (i >= DIGIT_NUM) {
            printf("%c ", 'a' + i - DIGIT_NUM);
        }

        for (int j = 0; j < char_histogram[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }

    return 0;
}