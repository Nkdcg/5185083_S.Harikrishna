#include <stdio.h>
#include <string.h>

#define MAX 201

int r, c, N;
char grid[MAX][MAX], temp[MAX][MAX];

void fill_full_bombs() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            temp[i][j] = 'O';
        }
        temp[i][c] = '\0';
    }
}

void detonate(char src[MAX][MAX]) {
    // Start with full bombs
    fill_full_bombs();
    // Mark cells to empty
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (src[i][j] == 'O') {
                temp[i][j] = '.';
                if (i > 0) temp[i - 1][j] = '.';
                if (i < r - 1) temp[i + 1][j] = '.';
                if (j > 0) temp[i][j - 1] = '.';
                if (j < c - 1) temp[i][j + 1] = '.';
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &r, &c, &N);
    for (int i = 0; i < r; i++) {
        scanf("%s", grid[i]);
    }

    if (N == 1) {
        // Just print the initial grid
        for (int i = 0; i < r; i++) {
            printf("%s\n", grid[i]);
        }
    } else if (N % 2 == 0) {
        // Full bombs
        fill_full_bombs();
        for (int i = 0; i < r; i++) {
            printf("%s\n", temp[i]);
        }
    } else {
        // First detonation
        detonate(grid);
        if (N % 4 == 3) {
            for (int i = 0; i < r; i++) {
                printf("%s\n", temp[i]);
            }
        } else {
            // Second detonation
            char first[MAX][MAX];
            for (int i = 0; i < r; i++)
                strcpy(first[i], temp[i]);
            detonate(first);
            for (int i = 0; i < r; i++) {
                printf("%s\n", temp[i]);
            }
        }
    }
    return 0;
}
