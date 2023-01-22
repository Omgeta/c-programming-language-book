#include <stdio.h>

#define BUFFER 10  // max word length
#define IN 1       // inside a word
#define OUT 0      // outside a word

int main() {
    int c, state;

    size_t curr_word_len = 0;
    int histogram[BUFFER];
    for (size_t i = 0; i < BUFFER; i++) { /* initialize all word length counts to 0 */
        histogram[i] = 0;
    }

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {  // count the length of words
            state = IN;
            curr_word_len++;
        } else if (state == IN) {  // add the word length to the histogram and reset the word length counter to 0
            state = OUT;
            histogram[curr_word_len - 1]++;
            curr_word_len = 0;
        }
    }

    /* Print histogram */
    printf("Histogram\n==========================\n");
    for (size_t i = 0; i < BUFFER; i++) {
        if (histogram[i] > 0) {
            printf("%2ld ", i + 1);
            for (int j = 0; j < histogram[i]; j++) {
                putchar('#');
            }
            putchar('\n');
        }
    }

    return 0;
}