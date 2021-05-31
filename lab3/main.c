#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define bool int
#define true 1
#define false 0

void solve(bool debug) {
    int n;
    int m;
    int i;
    int j;
    int value;
    int** matrix;
    bool** used;

    if(debug) {
        while (!scanf("%d%d", &n, &m) || n <= 0 || m <= 0 || n > MAX_SIZE || m > MAX_SIZE) {
            while (getchar() != '\n');
        }
    } else {
        printf("Enter matrix size parameters\n");
        while (!scanf("%d%d", &n, &m) || n <= 0 || m <= 0 || n > MAX_SIZE || m > MAX_SIZE) {
            printf("Inccorrect input, try again\n");
            while (getchar() != '\n');
        }
    }

    matrix = (int**)malloc(n * sizeof(int));
    used = (int**)malloc(n * sizeof(bool));
    for (i = 0; i < n; ++i) {
        matrix[i] = (int*)malloc(m * sizeof(int));
        used[i] = (int*)malloc(m * sizeof(int));
    }
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            used[i][j] = false; 
        }
    }

    while (true) {
        if (debug) {
            while (!scanf("%d%d%d", &i, &j, &value)) {
                while (getchar() != '\n');
            }
        } else {
            printf("Enter row number, column number and cell value\n");
            while (!scanf("%d%d%d", &i, &j, &value)) {
                printf("Inccorrect input, try again\n");
                while (getchar() != '\n');
            }
        }
        if (i == 0 && j == 0 && value == 0) {
            break;
        } else {
            --i;
            --j;
            if (i < 0 || i >= n || j < 0 || j >= m) {
                if (!debug) {
                    printf("Invalid row or column number value\n");
                }
            } else {
                if (used[i][j]) {
                    char answer;
                    if (debug) {
                        while (getchar() != '\n');
                        while (!scanf("%c", &answer)) {
                            while (getchar() != '\n');
                        }
                        if (answer == 'Y') {
                            matrix[i][j] = value;
                        }
                    } else {
                        printf("This matrix cell is already defined. Want change value? (Y/N)\n");
                        while (getchar() != '\n');
                        while (!scanf("%c", &answer) || answer != 'Y' && answer != 'N') {
                            printf("Inccorrect input, try again\n");
                            while (getchar() != '\n');
                        }
                        if (answer == 'Y') {
                            matrix[i][j] = value;
                        }
                    }
                } else {
                    used[i][j] = true;
                    matrix[i][j] = value;
                }     
            }
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (used[i][j]) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    solve(false);
    return 0;
}
