#include <stdio.h>

void conquer(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int leftArr[n1], rightArr[n2];
    
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];
    
    printf("Left Array: ");
    for (int i = 0; i < n1; i++) printf("%d ", leftArr[i]);
    printf("\n");
    
    printf("Right Array: ");
    for (int j = 0; j < n2; j++) printf("%d ", rightArr[j]);
    printf("\n");
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];
    }
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
    
    printf("Merged Array: ");
    for (int i = left; i <= right; i++) printf("%d ", arr[i]);
    printf("\n");
}

void divide(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        
        printf("Dividing: ");
        for (int i = left; i <= right; i++) printf("%d ", arr[i]);
        printf("\n");
        
        divide(arr, left, mid);
        divide(arr, mid + 1, right);
        conquer(arr, left, mid, right);
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    divide(arr, 0, n - 1);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

