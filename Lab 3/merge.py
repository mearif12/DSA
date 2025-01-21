def mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        
        # Print current subarray being divided
        print("Dividing:", end=" ")
        for i in range(left, right + 1):
            print(arr[i], end=" ")
        print()

        # Recursively divide the array into two halves
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)

        # Merge the two halves
        n1 = mid - left + 1
        n2 = right - mid
        leftArr = arr[left:left + n1]
        rightArr = arr[mid + 1:mid + 1 + n2]

        # Print left and right arrays before merging
        print("Left Array:", end=" ")
        for i in range(n1):
            print(leftArr[i], end=" ")
        print()

        print("Right Array:", end=" ")
        for i in range(n2):
            print(rightArr[i], end=" ")
        print()

        # Merge the two temporary arrays back into arr[]
        i = 0
        j = 0
        k = left
        while i < n1 and j < n2:
            if leftArr[i] <= rightArr[j]:
                arr[k] = leftArr[i]
                i += 1
            else:
                arr[k] = rightArr[j]
                j += 1
            k += 1

        # Copy remaining elements of leftArr[], if any
        while i < n1:
            arr[k] = leftArr[i]
            i += 1
            k += 1

        # Copy remaining elements of rightArr[], if any
        while j < n2:
            arr[k] = rightArr[j]
            j += 1
            k += 1

        # Print the merged array
        print("Merged Array:", end=" ")
        for i in range(left, right + 1):
            print(arr[i], end=" ")
        print()


def main():
    # Input the size of the array
    n = int(input("Enter the number of elements in the array: "))

    # Input the elements of the array
    arr = []
    print("Enter the elements of the array: ")
    for i in range(n):
        arr.append(int(input()))

    # Perform Merge Sort
    mergeSort(arr, 0, n - 1)

    # Output the sorted array
    print("Sorted array:", end=" ")
    for num in arr:
        print(num, end=" ")
    print()


if __name__ == "__main__":
    main()
