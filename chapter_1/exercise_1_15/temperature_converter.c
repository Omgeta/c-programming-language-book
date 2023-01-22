#include <stdio.h>

/*
    Prints Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating point version
*/
float celsius(float fahr);

int main() {
    float fahr;
    int lower, upper, step;

    lower = 0;    // lower limit of temperature table
    upper = 300;  // upper limit of temperature table
    step = 20;    // step size

    puts("Fah\tCel");
    puts("----------");
    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, celsius(fahr));
        fahr = fahr + step;
    }
}

float celsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}