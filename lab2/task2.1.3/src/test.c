#include "main.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

#define EPS 1e-9

double length(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void test(double len1, double len2, double len3, int poss, int type, double p, double s) {
    assert(possible(len1, len2, len3) == poss);
    assert(triangleType(len1, len2, len3) == type);
    assert(fabsf(perimeter(len1, len2, len3) - p) < EPS);
    assert(fabsf(area(len1, len2, len3) - s) < EPS);
}

#undef main

int main() {
    test(length(0, 0, 3, 0), length(3, 0, 3, 3), length(3, 3, 0, 0), 1, 6, 10.2426406871, 4.5);
    test(length(10, 26, 13, 26), length(117, 21, 117, 24), length(7, 3, 4, 0), 1, 6, 10.2426406871, 4.5);
    test(length(237.4, 5.7, 241.4, 5.7), length(2.1, 11, 0.1, 15), length(1036, 54.7, 1034, 50.7), 1, 2, 12.944271909, 8);
    test(length(1e9, 1e9, 0, 0), length(91447, 123, 15, 9272), length(0, 45, 8, 32), 0, 0, 0, 0);
    test(length(1486311823.3, 94617.1, 1857166731.3, 0), length(1246, 74.3, 74374.5, 9), length(8713, 45.2, 8090, 1024), 0, 0, 0, 0);
    test(length(456, 576, 1056, 576), length(645, 198, 345, 498), length(333, 496, 33, 196), 1, 6, 1448.528137424, 90000);
    test(length(847, 9182, 12, 16178), length(1684, 738, 6138, 9165), length(8117, 3162, 1324, 5474), 1, 0, 23752.975672191, 25147677.209505763);
    test(length(56, 520, 176, 580), length(1120, 1860, 1020, 1860), length(820, 162, 800, 102), 1, 0, 297.409631853, 3000);
    test(length(0, 0, 3, 0), length(3, 0, 0, 4), length(0, 4, 0, 0), 1, 4, 12, 6);
    test(length(9154, 9871, 9157, 9871), length(87, 1, 84, 5), length(9999, 1004, 9999, 1000), 1, 4, 12, 6);
    printf("Good job! All tests passed!\n");
    return 0;
}