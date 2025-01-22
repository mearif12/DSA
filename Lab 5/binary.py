def main():
    #Taking array size input
    n = int(input("Enter the number of elements: "))

    #Taking sorted array input
    arr = list(map(int, input(f"Enter {n} sorted elements: ").split()))

    #Taking target element input
    target = int(input("Enter the number to search: "))

    #Binary Search
    left = 0
    right = n - 1
    step = 1

    print("\nBinary Search Process:")

    while left <= right:
        mid = left + (right - left) // 2

        #Print the current step details
        print(f"Step {step}: Searching in range [{left+1} - {right+1}], Mid = arr[{mid+1}] = {arr[mid]}")
        print(f"Step {step}: Comparing target {target} with arr[{mid+1}] = {arr[mid]}")

        if arr[mid] == target:
            print(f"Target {target} found at position {mid + 1}")
            return
        elif arr[mid] < target:
            print(f"Target is greater than arr[{mid+1}], searching right half")
            left = mid + 1
        else:
            print(f"Target is less than arr[{mid+1}], searching left half")
            right = mid - 1

        step = step + 1

    print(f"Target {target} not found in the array")
  
if __name__ == "__main__":
    main()
