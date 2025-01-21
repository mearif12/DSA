def main():
    # Input the size of the array
    n = int(input("Enter the number of elements in the array: "))

    arr = []
    
    # Input the elements of the array
    print("Enter the elements of the array:")
    for _ in range(n):
        element = int(input())
        arr.append(element)

    # Bubble Sort logic
    for i in range(n - 1):
        for j in range(n - i - 1):
            print(f"Comparing {arr[j]} and {arr[j + 1]}")
            if arr[j] > arr[j + 1]:
                # Swap elements
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                print(f"Swapped {arr[j]} and {arr[j + 1]}")
            print("Current array state:", end=" ")
            for k in range(n):
                print(arr[k], end=" ")
            print()

        print(f"After pass {i + 1}, array state:", end=" ")
        for k in range(n):
            print(arr[k], end=" ")
        print()

    # Output the sorted array
    print("Sorted array in ascending order:", end=" ")
    for i in range(n):
        print(arr[i], end=" ")
    print()

if __name__ == "__main__":
    main()
