#include <limits.h>
#include <stdio.h>

int main() {
    printf("PLAIN CHAR RANGE: %d > %d\n", CHAR_MIN, CHAR_MAX);  // machine-dependent
    printf("UNSIGNED CHAR RANGE: %d > %d\n", 0, UCHAR_MAX);
    printf("SIGNED CHAR RANGE: %d > %d\n", SCHAR_MIN, SCHAR_MAX);

    printf("\n");

    printf("UNSIGNED SHORT RANGE: %d > %d\n", 0, USHRT_MAX);
    printf("SIGNED SHORT RANGE: %d > %d\n", SHRT_MIN, SHRT_MAX);

    printf("\n");

    printf("UNSIGNED INT RANGE: %u > %u\n", 0, UINT_MAX);
    printf("SIGNED INT RANGE: %d > %d\n", INT_MIN, INT_MAX);

    printf("\n");

    printf("UNSIGNED LONG RANGE: %lu > %lu\n", 0, ULONG_MAX);
    printf("SIGNED LONG RANGE: %ld > %ld\n", LONG_MIN, LONG_MAX);

    printf("\n");

    printf("UNSIGNED LONG LONG RANGE: %llu > %llu\n", 0, ULLONG_MAX);
    printf("SIGNED LONG LONG RANGE: %lld > %lld\n", LLONG_MIN, LLONG_MAX);

    return 0;
}