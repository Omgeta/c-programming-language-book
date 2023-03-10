#include <stdio.h>

/*
    Prints Celsius-Fahrenheit table
    for fahr = 0, 20, ..., 300; floating point version
*/
int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;    // lower limit of temperature table
    upper = 300;  // upper limit of temperature table
    step = 20;    // step size

    puts("Cel\tFah");
    puts("----------");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0f;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}