def hanoi(n, source, target, auxiliary):
    if n == 1:
        print(f"Move disk 1 from {source} to {target}")
        return
    hanoi(n - 1, source, auxiliary, target)  # Move n-1 disks to auxiliary peg
    print(f"Move disk {n} from {source} to {target}")  # Move largest disk to target
    hanoi(n - 1, auxiliary, target, source)  # Move n-1 disks from auxiliary to target

# Main function
n = int(input("Enter number of disks: "))
print(f"Total moves required: {2**n - 1}")
print(f"The sequence of moves involved in the Tower of Hanoi are:")
hanoi(n, 'A', 'C', 'B')  # Call function with pegs A (source), C (target), B (auxiliary)
