def main():
    profits = [0] * 100
    weights = [0] * 100
    dp = [[0] * 101 for _ in range(101)]
    
    # User input for number of items
    n = int(input("Enter the number of items: "))

    # User input for profits
    print("Enter the profits of the items:")
    for i in range(n):
        profits[i] = int(input(f"Profit of item {i + 1}: "))

    # User input for weights
    print("Enter the weights of the items:")
    for i in range(n):
        weights[i] = int(input(f"Weight of item {i + 1}: "))

    # User input for knapsack capacity
    capacity = int(input("Enter the capacity of the knapsack: "))

    # Initialize dp array (Base case: dp[0][w] and dp[i][0] = 0)
    for i in range(n + 1):
        for w in range(capacity + 1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif weights[i - 1] <= w:
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w])
                
                # Print decision-making process
                print(f"Considering item {i} (Profit: {profits[i - 1]}, Weight: {weights[i - 1]}) with capacity {w}")
                print(f"Include item {i}: {profits[i - 1]} + dp[{i - 1}][{w - weights[i - 1]}] = {dp[i][w]}")
                print(f"Exclude item {i}: dp[{i - 1}][{w}] = {dp[i - 1][w]}")
                print(f"dp[{i}][{w}] = {dp[i][w]}\n")
            else:
                dp[i][w] = dp[i - 1][w]

                # Print decision-making process
                print(f"Considering item {i} (Profit: {profits[i - 1]}, Weight: {weights[i - 1]}) with capacity {w}")
                print(f"Item too heavy to include. dp[{i}][{w}] = dp[{i - 1}][{w}] = {dp[i][w]}\n")

    # Output the DP table for clarity
    print("DP Table:")
    for i in range(n + 1):
        for w in range(capacity + 1):
            print(f"{dp[i][w]:3d}", end=" ")
        print()

    # Backtrack to find which items are included
    w = capacity
    print("\nItems included to achieve maximum profit:")
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:  # Item i is included
            print(f"Item {i} (Profit: {profits[i - 1]}, Weight: {weights[i - 1]})")
            w -= weights[i - 1]  # Decrease the remaining capacity

    # Output the maximum profit
    print(f"Maximum profit in the knapsack: {dp[n][capacity]}")

if __name__ == "__main__":
    main()
