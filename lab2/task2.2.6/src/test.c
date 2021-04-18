#include "main.h"
#include <assert.h>
#include <stdio.h>

#undef main

int main() {
    assert(solve(30, 0.01) == 2);
    assert(solve(30, 0.1) == 1);
    assert(solve(30, 0.0004) == 2);
    assert(solve(30, 0.000003) == 3);
    assert(solve(30, 0.00001) == 3);
    assert(solve(30, 0.00000001) == 4);
    assert(solve(30, 0.000000009) == 4);
    assert(solve(30, 0.000000000021) == 5);
    assert(solve(30, 0.0000000001) == 5);
    assert(solve(30, 0.00000000003) == 5);
    assert(solve(45, 0.1) == 1);
    assert(solve(45, 0.09) == 1);
    assert(solve(45, 0.01) == 2);
    assert(solve(45, 0.004) == 2);
    assert(solve(45, 0.001) == 3);
    assert(solve(45, 0.000001) == 4);
    assert(solve(45, 0.000000002) == 5);
    assert(solve(45, 0.00000001) == 5);
    assert(solve(60, 0.02) == 2);
    assert(solve(60, 0.001) == 3);
    assert(solve(60, 0.00001) == 4);
    assert(solve(60, 0.000005) == 4);
    assert(solve(60, 0.0000001) == 5);
    assert(solve(60, 0.00000005) == 5);
    printf("Good job! All tests passed!");
    return 0;
}
