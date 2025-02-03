#include <stdio.h>

#define N 4  // Change this for different board sizes

int main() {
    int placed[N], row = 0, col = 0, solutionCount = 0;

    while (row >= 0) {
        int found = 0;
        printf("\nTrying to place a queen in row %d...\n", row);

        while (col < N) {
            printf("Checking (%d, %d)... ", row, col);
            int safe = 1;

            for (int prev = 0; prev < row; prev++) {
                if (placed[prev] == col || 
                    placed[prev] - prev == col - row || 
                    placed[prev] + prev == col + row) {
                    printf("Conflict with queen at (%d, %d)\n", prev, placed[prev]);
                    safe = 0;
                    break;
                }
            }

            if (safe) {
                placed[row] = col;
                printf("Placed queen at (%d, %d)\n", row, col);
                row++;
                col = 0;  // Reset for next row
                found = 1;
                break;
            }
            col++;
        }

        if (!found) {
            row--;
            if (row >= 0) {
                col = placed[row] + 1;
                printf("Backtracking to row %d, trying next column %d\n", row, col);
            }
        }

        if (row == N) {
            printf("\nSolution %d found:\n", ++solutionCount);
            for (int i = 0; i < N; i++, printf("\n"))
                for (int j = 0; j < N; j++)
                    printf("%c ", (placed[i] == j) ? 'Q' : '.');

            row--;  // Backtrack for more solutions
            col = placed[row] + 1;
        }
    }

    printf("\nTotal solutions found: %d\n", solutionCount);
}

