#include <stdio.h>
#define MAX 5 // Maximum size of the queue

int queue[MAX], front = -1, rear = -1;

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue
                if (rear == MAX - 1) {
                    printf("Queue is full! Cannot enqueue.\n");
                } else {
                    if (front == -1) { // Set front if queue is initially empty
                        front = 0;
                    }
                    printf("Enter the value to enqueue: ");
                    scanf("%d", &value);
                    rear++;
                    queue[rear] = value;
                    printf("%d enqueued to the queue.\n", value);
                    printf("Current front: %d, rear: %d\n", front, rear);
                }
                break;

            case 2: // Dequeue
                if (front == -1 || front > rear) {
                    printf("Queue is empty! Cannot dequeue.\n");
                } else {
                    printf("Dequeued value: %d\n", queue[front]);
                    front++;
                    printf("Current front: %d, rear: %d\n", front, rear);
                    if (front > rear) { // Reset the queue when all elements are dequeued
                        front = rear = -1;
                        printf("Queue is now empty.\n");
                    }
                }
                break;

            case 3: // Display
                if (front == -1 || front > rear) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Queue elements are: ");
                    for (int i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;

            case 4: // Exit
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }

        //EXTRA:> Show current state of the queue after each operation
        if (front == -1 || front > rear) {
            printf("Queue is empty.\n");
        } else {
            printf("Current queue: ");
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
