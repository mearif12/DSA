#include <stdio.h>

int main() {
    int n, target, left, right, mid, step = 1;
    
    //Taking array size input
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    //Taking sorted array input
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Taking target element input
    printf("Enter the number to search: ");
    scanf("%d", &target);

    //Binary Search Logic
    left = 0;right = n - 1;

    printf("\nBinary Search Process:\n");

    while (left <= right) {
        mid = left + (right - left) / 2;

        //Print the current step details
        printf("Step %d: Searching in range [%d - %d], Mid = arr[%d] = %d\n", step, left+1, right+1, mid+1, arr[mid]);
        printf("Step %d: Comparing target %d with arr[%d] = %d\n", step, target, mid+1, arr[mid]);

        if (arr[mid] == target) {
            printf("Target %d found at possition %d\n", target, mid+1);
            return 0;
        } else if (arr[mid] < target) {
            printf("Target is greater than arr[%d], searching right half\n", mid);
            left = mid + 1;
        } else {
            printf("Target is less than arr[%d], searching left half\n", mid);
            right = mid - 1;
        }

        step++;
    }

    printf("Target %d not found in the array\n", target);

    return 0;
}
