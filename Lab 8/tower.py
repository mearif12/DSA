def towers(n, from_peg, to_peg, aux_peg):
    if n == 1:
        print(f"Move disk 1 from peg {from_peg} to peg {to_peg}")
        return
    towers(n - 1, from_peg, aux_peg, to_peg)  # Move n-1 disks from source to auxiliary
    print(f"Move disk {n} from peg {from_peg} to peg {to_peg}")  # Move nth disk
    towers(n - 1, aux_peg, to_peg, from_peg)  # Move n-1 disks from auxiliary to destination

def main():
    # Input number of disks
    num = int(input("Enter the number of disks: "))

    total_moves = (1 << num) - 1  # 2^n - 1
    print(f"The total number of moves: {total_moves}")

    print("The sequence of moves involved in the Tower of Hanoi are:")
    
    # Call the recursive function with initial parameters
    towers(num, 'A', 'C', 'B')

if __name__ == "__main__":
    main()
