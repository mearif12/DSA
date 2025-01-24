#include <stdio.h>

#define N 4  // Change this value to solve for different N

int main() {
    int board[N][N] = {0};  // Chessboard initialized to 0
    int placed[N]; // Track queen column positions per row
    int solutionCount = 0;

    int row = 0, col = 0;  // Starting position

    while (row >= 0) { // Backtracking control
        int found = 0; // Flag to check if queen can be placed
        
        // Try placing a queen in a valid column
        for (; col < N; col++) {
            int safe = 1;
            
            // Check column and diagonals
            for (int prev = 0; prev < row; prev++) {
                if (placed[prev] == col ||  // Same column
                    placed[prev] - prev == col - row ||  // Same diagonal (\)
                    placed[prev] + prev == col + row) {  // Same diagonal (/)
                    safe = 0;
                    printf("Cannot place queen at (%d, %d) -> Conflict with queen at (%d, %d)\n", row, col, prev, placed[prev]);
                    break;
                }
            }

            if (safe) {  // Place the queen
                board[row][col] = 1;
                placed[row] = col;
                printf("Placed queen at (%d, %d)\n", row, col);

                // Print board
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++)
                        printf("%c ", board[i][j] ? 'Q' : '.');
                    printf("\n");
                }
                printf("\n");

                row++;  // Move to next row
                col = 0; // Reset column search
                found = 1;
                break;
            }
        }

        if (!found) {  // No valid position, backtrack
            row--;
            if (row >= 0) {
                col = placed[row] + 1; // Move to the next column
                board[row][placed[row]] = 0; // Remove queen
                printf("Backtracking from row %d, trying next column %d\n", row, col);
            }
        }

        if (row == N) {  // Found a solution
            printf("Solution %d found:\n", ++solutionCount);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++)
                    printf("%c ", board[i][j] ? 'Q' : '.');
                printf("\n");
            }
            printf("\n");
            //break; // Stop searching for more solutions
        }
    }
    // Print total number of solutions found
    printf("Total solutions found: %d\n", solutionCount);
    if (solutionCount == 0)
        printf("No solution exists for N = %d\n", N);

    return 0;
} 
