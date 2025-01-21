#include <stdio.h>

int main() {
    int n, key, found = 0;

    //Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    //Input the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Input the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    //Linear Search Logic
    for (int i = 0; i < n; i++) {
        //Print the current comparison
        printf("Comparing %d with %d\n", arr[i], key);
        if (arr[i] == key) {
            printf("Element %d found at index %d.\n", key, i+1);
            found = 1;
            break;
        }
    }

    //If the element is not found
    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}  
