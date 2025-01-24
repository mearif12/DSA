N = 4  # Change this value to solve for different N

# Initialize the chessboard and other variables
board = [[0] * N for _ in range(N)]
placed = [-1] * N  # Track queen column positions per row
solution_count = 0

row = 0
col = 0  # Starting position

while row >= 0:  # Backtracking control
    found = 0  # Flag to check if queen can be placed

    # Try placing a queen in a valid column
    for col in range(col, N):
        safe = 1
        
        # Check column and diagonals
        for prev in range(row):
            if (placed[prev] == col or  # Same column
                placed[prev] - prev == col - row or  # Same diagonal (\)
                placed[prev] + prev == col + row):  # Same diagonal (/)
                safe = 0
                print(f"Cannot place queen at ({row}, {col}) -> Conflict with queen at ({prev}, {placed[prev]})")
                break

        if safe:  # Place the queen
            board[row][col] = 1
            placed[row] = col
            print(f"Placed queen at ({row}, {col})")

            # Print board
            for i in range(N):
                for j in range(N):
                    print('Q' if board[i][j] else '.', end=' ')
                print()
            print()

            row += 1  # Move to next row
            col = 0   # Reset column search
            found = 1
            break

    if not found:  # No valid position, backtrack
        row -= 1
        if row >= 0:
            col = placed[row] + 1  # Move to the next column
            board[row][placed[row]] = 0  # Remove queen
            print(f"Backtracking from row {row}, trying next column {col}")

    if row == N:  # Found a solution
        print(f"Solution {solution_count + 1} found:")
        for i in range(N):
            for j in range(N):
                print('Q' if board[i][j] else '.', end=' ')
            print()
        print()
        solution_count += 1

# Print total number of solutions found
print(f"Total solutions found: {solution_count}")
if solution_count == 0:
    print(f"No solution exists for N = {N}")
