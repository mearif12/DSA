def knapsack():
    n = int(input("Enter the number of items: "))
    profits, weights = [], []

    # Input profits and weights
    for i in range(n):
        profits.append(int(input(f"Profit of item {i + 1}: ")))
    for j in range(n):    
        weights.append(int(input(f"Weight of item {j + 1}: ")))

    capacity = int(input("Enter the capacity of the knapsack: "))
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    # Dynamic Programming table filling
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                include = profits[i - 1] + dp[i - 1][w - weights[i - 1]]
                exclude = dp[i - 1][w]
                dp[i][w] = max(include, exclude)

                # Print decision-making process
                print(f"Considering item {i} (Profit: {profits[i - 1]}, Weight: {weights[i - 1]}) with capacity {w}")
                print(f"Include item {i}: {profits[i - 1]} + dp[{i - 1}][{w - weights[i - 1]}] = {dp[i][w]}")
                print(f"Exclude item {i}: dp[{i - 1}][{w}] = {exclude}")
            else:
                dp[i][w] = dp[i - 1][w]
                print(f"Item {i} too heavy for capacity {w}, dp[{i}][{w}] = {dp[i][w]}")

            print(f"dp[{i}][{w}] = {dp[i][w]}\n")

    # Display DP table
    print("DP Table:")
    for row in dp:
        print(" ".join(f"{x:2d}" for x in row))

    # Backtrack to find selected items
    w = capacity
    print("\nItems included for maximum profit:")
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:  # Item is included
            print(f"Item {i} (Profit: {profits[i - 1]}, Weight: {weights[i - 1]})")
            w -= weights[i - 1]

    print(f"Maximum profit in the knapsack: {dp[n][capacity]}")

if __name__ == "__main__":
    knapsack()
