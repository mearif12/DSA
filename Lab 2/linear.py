def main():
    # Input the size of the array
    n = int(input("Enter the number of elements in the array: "))

    arr = []
    
    # Input the elements of the array
    print("Enter the elements of the array:")
    for _ in range(n):
        element = int(input())
        arr.append(element)

    # Input the element to search
    key = int(input("Enter the element to search: "))

    # Perform Linear Search
    found = False
    for i in range(n):
        # Print the current comparison
        print(f"Comparing {arr[i]} with {key}")
        
        if arr[i] == key:
            print(f"Element {key} found at index {i + 1}.")
            found = True
            break

    # If the element is not found
    if not found:
        print(f"Element {key} not found in the array.")

if __name__ == "__main__":
    main()
