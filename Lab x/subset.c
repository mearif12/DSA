#include <stdio.h>

int main() {
    int N, target_sum;
    
    // Input for set elements
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    
    int S[N];
    printf("Enter the elements: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }
    
    // Input for target sum
    printf("Enter the target sum: ");
    scanf("%d", &target_sum);
    
    int total_subsets = 1 << N; // 2^N subsets//pow(2,N)
    printf("The total subsets of %d is: %d\n", target_sum, total_subsets);
    
    int count = 0;
    printf("Subsets with sum %d:\n", target_sum);
    
    for (int mask = 0; mask < total_subsets; mask++) {
        int subset_sum = 0;
        printf("{ ");
        
        // Generate subset based on current mask
        for (int j = 0; j < N; j++) {
            if (mask & (1 << j)) { // Check if j-th element is in subset
                printf("%d ", S[j]);
                subset_sum += S[j];
            }
        }
        
        printf("}");
        
        // Check if the subset sum equals target sum
        if (subset_sum == target_sum) {
            printf(" FOUND");
            count++;
        }
        printf("\n");
    }
    
    // Print total count of valid subsets
    printf("Total subsets found: %d\n", count);
    
    return 0;
}
