#include <stdio.h>
#include <stdlib.h>
#include "str.h"

#define MAX_LENGTH 1024

char *getString() {
    printf("Enter a string\n");
    char *result = malloc(sizeof(char) * MAX_LENGTH);
    gets(result);
    return result;
}

void correctFormat(char *s) {
    char *result = malloc(sizeof(char) * MAX_LENGTH);
    int i = 0;
    int j = 0;
    for (i = 0; i < length(s); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[j] = s[i];
            ++j;
        }
    }
    s[j] = '\0';
}

char *solve(char *s, char *t) {
    correctFormat(s);
    correctFormat(t);
    int** dp = (int**)malloc(length(s) * sizeof(int));
    int i;
    int j;
    for (i = 0; i < length(s); ++i) {
        dp[i] = (int*)malloc(length(t) * sizeof(int));
    }
    for (i = 0; i < length(s); ++i) {
        if (s[i] == t[0]) {
            dp[i][0] = 1;
        } else {
            dp[i][0] = 0;
        }
    }
    for (j = 0; j < length(t); ++j) {
        if (t[j] == s[0]) {
            dp[0][j] = 1;
        } else {
            dp[0][j] = 0;
        }
    }
    int x = 0;
    int y = 0;
    for (i = 1; i < length(s); ++i) {
        for (j = 1; j < length(t); ++j) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }
            if (dp[i][j] > dp[x][y]) {
                x = i;
                y = j;
            }
        }
    }
    char *result = malloc(sizeof(char) * dp[x][y]);
    if (dp[x][y] == 0) {
        result = "ERROR: STRING DONT HAVE COMMON SUBSTRING\n";
    } else {
        for (i = dp[x][y] - 1; i >= 0; --i, --x) {
            result[i] = s[x];
        }
    }
    return result;
}

int main() {
    char *s = getString();
    char *t = getString();
    char *answer = solve(s, t);
    printf("%s\n", answer);
    free(s);
    free(t);
    free(answer);
    return 0;
}