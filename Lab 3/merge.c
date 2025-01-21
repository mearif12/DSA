#include <stdio.h>

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        
        //Print current subarray being divided
        printf("Dividing: ");
        for (int i = left; i <= right; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        //Recursively divide the array into two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        //Merge the two halves
        int n1 = mid - left + 1, n2 = right - mid;
        int leftArr[n1], rightArr[n2];

        for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];

        //Print left and right arrays before merging
        printf("Left Array: ");
        for (int i = 0; i < n1; i++) {
            printf("%d ", leftArr[i]);
        }
        printf("\n");

        printf("Right Array: ");
        for (int j = 0; j < n2; j++) {
            printf("%d ", rightArr[j]);
        }
        printf("\n");

        //Merge the two temporary arrays back into arr[]
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];
        }

        while (i < n1) arr[k++] = leftArr[i++];
        while (j < n2) arr[k++] = rightArr[j++];

        //Print the merged array
        printf("Merged Array: ");
        for (int i = left; i <= right; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    //Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    //Input the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    //Output the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
