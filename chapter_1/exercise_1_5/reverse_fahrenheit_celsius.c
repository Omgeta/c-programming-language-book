#include <stdio.h>

/*
    Prints Fahrenheit-Celsius table
    for fahr = 300, 280, ..., 0; floating point version
*/
int main() {
    float fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3.0f %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}