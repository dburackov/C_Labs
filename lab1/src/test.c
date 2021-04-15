#include "main.h"
#include <stdio.h>
#include <assert.h>

void test() {
    assert(solve(12) == 6);
    assert(solve(23) == 0);
    assert(solve(50) == 4);
    assert(solve(1) == 1);
    assert(solve(7) == 1);
    assert(solve(61) == 9);
    assert(solve(100) == 2);
    assert(solve(75) == 1);
    assert(solve(4) == 7);
    assert(solve(101) == 1);
    assert(solve(88) == 2);
    assert(solve(7497) == 6);
    assert(solve(5138) == 7);
    assert(solve(256) == 8);
    assert(solve(128) == 3);
    assert(solve(64) == 0);
    assert(solve(32) == 2);
    printf("Good job! All tests passed!\n");
}

#undef main

int main() {
    test();
    return 0;
}