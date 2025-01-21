#include <stdio.h>

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort logic
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf("Comparing %i and %i\n",arr[j],arr[j+1]);
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printf("Swapped %i and %i\n",arr[j],arr[j+1]);
            }
            printf("Current array state: ");
            for(int k=0;k < n;k++){
                printf("%i ",arr[k]);
            }
            printf("\n");
        }
        printf("After pass %i, array state: ",i+1);
        for(int k = 0;k < n;k++){
            printf("%i ",arr[k]);
        }
        printf("\n");
    }

    // Output the sorted array
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
