def main():
    queue = []  # Initialize an empty queue
    
    while True:
        print("\nQueue Operations:")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Display")
        print("4. Exit")
        
        choice = int(input("Enter your choice: "))

        if choice == 1:  # Enqueue
            value = int(input("Enter the value to enqueue: "))
            queue.append(value)
            print(f"{value} enqueued to the queue.")
        
        elif choice == 2:  # Dequeue
            if queue:
                print(f"Dequeued value: {queue.pop(0)}")
            else:
                print("Queue is empty! Cannot dequeue.")
        
        elif choice == 3:  # Display
            if queue:
                print("Queue elements are:", *queue)
                print(f"Front: {queue[0]}, Rear: {queue[-1]}")
            else:
                print("Queue is empty!")
        
        elif choice == 4:  # Exit
            print("Exiting...")
            break
        
        else:
            print("Invalid choice! Try again.")
        
        # Show current state of the queue after each operation
        if queue:
            print("Current queue:", *queue)
        else:
            print("Queue is empty.")    

if __name__ == "__main__":
    main()
