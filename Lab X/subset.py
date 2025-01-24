# Take input for the set elements
S = list(map(int, input("Enter the elements: ").split()))

# Calculate the number of elements in the set
N = len(S)

# Take input for target sum
target_sum = int(input("Enter the target sum: "))

# Generate all subsets using bitmask
total_subsets = 1 << N  # 2^N subsets
print(f"The total subsets of {target_sum} is: {total_subsets}")

count = 0
print(f"Subsets with sum {target_sum}:")

for mask in range(total_subsets):
    subset = []
    subset_sum = 0

    # Generate the subset based on the current mask
    for j in range(N):
        if mask & (1 << j):  # Check if j-th element is in the subset
            subset.append(S[j])
            subset_sum += S[j]

    # Print the current subset
    print("{", " ".join(map(str, subset)), "}", end="")

    # Check if the subset sum equals the target sum
    if subset_sum == target_sum:
        print(" FOUND")  # Mark valid subset
        count += 1  # Count valid subsets
    else:
        print()  # Just print a newline if not found

# Print total count of valid subsets
print(f"Total subsets found: {count}")
