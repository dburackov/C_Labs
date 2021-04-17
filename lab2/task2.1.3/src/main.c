#include <stdio.h>
#include <math.h>

#define true 1
#define false 0
#define MAX_PARAMETER_VALUE 1e6
#define EPS 1e-9
#define sqr(x) (x)*(x)

struct point {
    double x;
    double y;
};

struct segment {
    struct point first;
    struct point second;
    double length;
};

double getDouble() {
    double result = 0;
    while (!scanf("%lf", &result) || result < -MAX_PARAMETER_VALUE || result > MAX_PARAMETER_VALUE) {
        printf("Incorrect input! Try again.\n");
        while (getchar() != '\n');
    }
    return result;
}

struct segment getSegment() {
    struct segment result;
    printf("X coordinate of the first point\n");
    result.first.x = getDouble();
    printf("Y coordinate of the first point\n");
    result.first.y = getDouble();
    printf("X coordinate of the second point\n");
    result.second.x = getDouble();
    printf("Y coordinate of the second point\n");
    result.second.y = getDouble();
    result.length = sqrt(sqr(result.first.x - result.second.x) + sqr(result.first.y - result.second.y));
    return result;
}

int possible(double lengthA, double lengthB, double lengthC) {
    int result = true;
    if (lengthA >= lengthB + lengthC) {
        result = false;
    }
    if (lengthB >= lengthA + lengthC) {
        result = false;
    }
    if (lengthC >= lengthA + lengthB) {
        result = false;
    }
    return result;
}

double perimeter(double lengthA, double lengthB, double lengthC) {
    double result = 0;
    if (possible(lengthA, lengthB, lengthC)) {
        result = lengthA + lengthB + lengthC;
    } 
    return result;
}

double area(double lengthA, double lengthB, double lengthC) {
    double result = 0;
    if (possible(lengthA, lengthB, lengthC)) {
        double p = perimeter(lengthA, lengthB, lengthC) / 2;
        result = sqrt(p * (p - lengthA) * (p - lengthB) * (p - lengthC));
    }
    return result;
}

double fabsf(double value) {
    return value < 0? value * -1 : value;
}

int triangleType(double lengthA, double lengthB, double lengthC) {
    int result = 0;
    if (possible(lengthA, lengthB, lengthC)) {
        if (lengthA == lengthB == lengthC) {
            result += 1;
        } 
        if (lengthA == lengthB || lengthA == lengthC || lengthB == lengthC) {
            result += 2;
        }
        if (fabsf(sqr(lengthA) - sqr(lengthB) - sqr(lengthC)) < EPS) {
            result += 4;        
        }
        if (fabsf(sqr(lengthB) - sqr(lengthA) - sqr(lengthC)) < EPS) {
            result += 4;
        }
        if (fabsf(sqr(lengthC) - sqr(lengthA) - sqr(lengthB)) < EPS) {
            result += 4;
        }
    }
    return result;
}

int main() {
    int stop = 0;
    int initialized = false;
    struct segment segA;
    struct segment segB;
    struct segment segC;
    while (!stop) {
        printf("\n");
        printf("1. Enter the coordinates of begin and end of three segments in two-dimensional space.\n");
        printf("2. Check that these segments can be used to form a triangle\n");
        printf("3. Determine triangle type\n");
        printf("4. Calculate the perimeter of the triangle\n");
        printf("5. Calculate the area of the triangle\n");
        printf("6. Information about the version and the author of the program.\n");
        printf("7. Exit\n");
        int menuCase = 0;
        while (!scanf("%d", &menuCase) || menuCase < 1 || menuCase > 7) {
            printf("Incorrect input! Try again.\n");
            while (getchar() != '\n'); 
        }
        switch (menuCase) {
            case 1:
                printf("Enter parameters of the first segment:\n");
                segA = getSegment();
                printf("Enter parameters of the second segment:\n");
                segB = getSegment();
                printf("Enter parameters of the third segment:\n");
                segC = getSegment();
                initialized = true;
                break;
            case 2:
                if (initialized) {
                    if (possible(segA.length, segB.length, segC.length)) {
                        printf("These segments can form triangle\n");
                    } else {
                        printf("These segments can't form triangle\n"); 
                    }
                } else {
                    printf("The segments are not initialized\n");
                }
                break;
            case 3:
                if (initialized) {
                    if (triangleType(segA.length, segB.length, segC.length) & 1 == 1) {
                        printf("This is equilateral triangle\n");
                        } 
                    if ((triangleType(segA.length, segB.length, segC.length) >> 1) & 1 == 1) {
                        printf("This is isosceles triangle\n");
                    }
                    if ((triangleType(segA.length, segB.length, segC.length) >> 2) & 1 == 1) {
                        printf("This is right triangle\n");
                    }
                } else {
                    printf("The segments are not initialized\n");
                }
                break;
            case 4:
                if (initialized) {
                    if (possible(segA.length, segB.length, segC.length)) {
                        printf("%.4f\n", perimeter(segA.length, segB.length, segC.length));
                    } else {
                        printf("These segments can't form triangle\n");
                    }
                } else {
                    printf("The segments are not initialized\n");
                }
                break;
            case 5:
                if (initialized) {
                    if (possible(segA.length, segB.length, segC.length)) {
                        printf("%.4f\n", area(segA.length, segB.length, segC.length));
                    } else {
                        printf("These segments can't form triangle\n");
                    }
                } else {
                    printf("The segments are not initialized\n");
                }
                break;
            case 6:
                printf("task 2.1 (3) (lab2-2.1-3) 6.3.0a\nDmitry Burakov 053501\n");
                break; 
            case 7:
                stop = true;
                break;
        }
    }
    return 0;
}