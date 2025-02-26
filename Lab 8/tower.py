def hanoi(n, source, target, auxiliary, count):
    if n == 1:
        count[0] += 1  
        print(f"{count[0]}: Move disk 1 from {source} to {target}")
        return
    hanoi(n - 1, source, auxiliary, target, count) 
    count[0] += 1
    print(f"{count[0]}: Move disk {n} from {source} to {target}")  
    hanoi(n - 1, auxiliary, target, source, count)  

n = int(input("Enter number of disks: "))
print(f"Total moves required: {2**n - 1}")
print("The sequence of moves involved in the Tower of Hanoi are:")
count = [0] 
hanoi(n, 'A', 'C', 'B', count)
