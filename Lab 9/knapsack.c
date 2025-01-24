#include <stdio.h>

int main() {
    int profits[100], weights[100];
    int dp[101][101];
    int n, capacity;

    // User input for number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // User input for profits
    printf("Enter the profits of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Profit of item %d: ", i + 1);
        scanf("%d", &profits[i]);
    }

    // User input for weights
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    // User input for knapsack capacity
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

     // Initialize dp array (Base case: dp[0][w] and dp[i][0] = 0)
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = (profits[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) ?
                            profits[i - 1] + dp[i - 1][w - weights[i - 1]] : dp[i - 1][w];
                 // Print decision-making process
                printf("Considering item %d (Profit: %d, Weight: %d) with capacity %d\n", 
                        i, profits[i - 1], weights[i - 1], w);
                printf("Include item %d: %d + dp[%d][%d] = %d\n", 
                        i, profits[i - 1], i - 1, w - weights[i - 1],dp[i][w]);
                printf("Exclude item %d: dp[%d][%d] = %d\n", 
                        i, i - 1, w,dp[i - 1][w]);
                printf("dp[%d][%d] = %d\n\n", i, w, dp[i][w]);
            } else {
                dp[i][w] = dp[i - 1][w];

                // Print decision-making process
                printf("Considering item %d (Profit: %d, Weight: %d) with capacity %d\n", 
                        i, profits[i - 1], weights[i - 1], w);
                printf("Item too heavy to include. dp[%d][%d] = dp[%d][%d] = %d\n\n", 
                        i, w, i - 1, w, dp[i][w]);
            }
        }
    }

    // Output the DP table for clarity
    printf("DP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            printf("%3d ", dp[i][w]);
        }
        printf("\n");
    }

    // Backtrack to find which items are included
    int w = capacity;
    printf("\nItems included to achieve maximum profit:\n");
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {  // Item i is included
            printf("Item %d (Profit: %d, Weight: %d)\n", i, profits[i - 1], weights[i - 1]);
            w = w - weights[i - 1];  // Decrease the remaining capacity
        }
    }

    // Output the maximum profit
    printf("Maximum profit in the knapsack: %d\n", dp[n][capacity]);

    return 0;
}
