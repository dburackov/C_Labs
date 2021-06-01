#include <stdio.h>
#include <stdlib.h>

#define FILENAME "input.txt"
#define DEBUG_FILE "output.txt"
#define MAX_WORD_LENGTH 200

void solve(char* file, int debug) {
    FILE* text = fopen(file, "r");
    int* count = malloc(sizeof(int) * MAX_WORD_LENGTH);
    int i = 0;
    for (; i < MAX_WORD_LENGTH; ++i) {
        count[i] = 0;
    }
    char symbol;
    int current = 0;
    while ((symbol = fgetc(text)) != EOF) {
        if (symbol >= 'A' && symbol <= 'Z' || symbol >= 'a' && symbol <= 'z') {
            ++current;
        } else {
            if (current < MAX_WORD_LENGTH) {
                ++count[current];
            }
            current = 0;
        }
    }
    if (current > 0 && current < MAX_WORD_LENGTH) {
        ++count[current];
    }
    fclose(text);
    if (debug) {
        text = fopen(DEBUG_FILE, "w");
        for (i = 1; i < MAX_WORD_LENGTH; ++i) {
            if (count[i] > 0) {
                fprintf(text, "%d %d\n", i, count[i]);
            }
        }
        fclose(text);
    } else {
        for (i = 1; i < MAX_WORD_LENGTH; ++i) {
            if (count[i] > 0) {
                printf("%3d |", i);
                int j = 0;
                for (; j < count[i]; ++j) {
                    printf("=");
                }
                printf(" %d\n", count[i]);
            }
        }
    }
    free(count);
}

int main() {
    solve(FILENAME, 0);
    return 0;
}