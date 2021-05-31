#include "main.h"
#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#undef main

#define MAX_LENGTH 1024

int test(char* fileName) {
    int result = 0;
    FILE *in = fopen(fileName, "r");
    char *s = malloc(sizeof(char) * MAX_LENGTH);
    char *t = malloc(sizeof(char) * MAX_LENGTH);
    char *answer = malloc(sizeof(char) * MAX_LENGTH);
    fgets(s, sizeof(char) * MAX_LENGTH, in);
    fgets(t, sizeof(char) * MAX_LENGTH, in);
    fgets(answer, sizeof(char) * MAX_LENGTH, in);
    answer[length(answer) - 1] = '\0';
    if (equals(answer, solve(s, t))) {
        result = 1;
    }
    free(s);
    free(t);
    free(answer);
    fclose(in);
    return result;
}

int main() {
    assert(test("tests/test1.txt") == 1);    
    assert(test("tests/test2.txt") == 1); 
    assert(test("tests/test3.txt") == 1);    
    assert(test("tests/test4.txt") == 1);    
    return 0;
}