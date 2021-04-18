#include <stdio.h>
#include <math.h>

#define PI 3.141592653

double getDouble(double lowerBound, double upperBound, char* text) {
    double result = 0;
    printf("Enter %s in the range %.0f to %.0f\n", text);
    while (!scanf("%lf", &result) || result < lowerBound || result > upperBound) {
        printf("Incorrect input! Try again.\n");
        while (getchar() != '\n');
    }
    return result;
}

int solve(double x, double eps) {
    x = x * PI / 180;
    double sinx = sin(x);
    double decomposition = x;
    double factorial = 1;
    double powx = x;
    int n = 1; 
    while (fabs(sinx - decomposition) > eps) {
        ++n;
        factorial *= 2 * (n - 1) * (2 * n - 1);
        powx *= x * x;  
        if (n % 2 == 1) {
            decomposition += powx / factorial;
        } else {
            decomposition -= powx / factorial;
        }
    }
    return n;
}

int main() {
    printf("%d\n", solve(getDouble(0, 90, "X"), getDouble(0, 2, "Eps")));
    return 0;
}