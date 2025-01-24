
#include <stdio.h>

int main() {
    int num; // Number of disks

    // Input number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &num);

    int total_moves = (1 << num) - 1;//2^n-1//pow(2,num)
    printf("The total number of moves:%d ",total_moves);
   
    printf("\nThe sequence of moves involved in the Tower of Hanoi are:\n");

    // Recursive logic for Tower of Hanoi embedded in main()
    void towers(int n, char from_peg, char to_peg, char aux_peg) {
        if (n == 1) {
            printf("Move disk 1 from peg %c to peg %c\n", from_peg, to_peg);
            return;
        }
        towers(n - 1, from_peg, aux_peg, to_peg); // Move n-1 disks from source to auxiliary
        printf("Move disk %d from peg %c to peg %c\n", n, from_peg, to_peg); // Move nth disk
        towers(n - 1, aux_peg, to_peg, from_peg); // Move n-1 disks from auxiliary to destination
    }

    // Call the recursive function with initial parameters
    towers(num, 'A', 'C', 'B');

    return 0;
}
