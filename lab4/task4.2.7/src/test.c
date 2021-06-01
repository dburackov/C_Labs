#include "main.h"
#include <assert.h>
#include <stdio.h>

#undef main

int fileCmp(char* file1, char* file2) {
    FILE* f1 = fopen(file1, "r");
    FILE* f2 = fopen(file2, "r");
    char ch1 = '\0';
    char ch2 = '\0';
    while (ch1 == ch2 && !feof(f1) && !feof(f2)) {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);
    }
    return ch1 == ch2;
} 

int test(char* inputFile, char* answerFile) {
    solve(inputFile, 1);
    return fileCmp("output.txt", answerFile);
}

int main() {
    assert(test("tests/test1.txt", "tests/answer1.txt") == 1);
    assert(test("tests/test2.txt", "tests/answer2.txt") == 1);
    assert(test("tests/test3.txt", "tests/answer3.txt") == 1);
    assert(test("tests/test4.txt", "tests/answer4.txt") == 1);
    printf("All tests pased\n");
    return 0;
}
