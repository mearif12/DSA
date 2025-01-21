#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], pattern[1000];

    // Take user input for text and pattern
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove newline character if present

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';  // Remove newline character if present

    int textLen = strlen(text);
    int patternLen = strlen(pattern);

    // Naive Pattern Matching Algorithm
    for (int i = 0; i <= textLen - patternLen; i++) {
        int j = 0;

        // Check if pattern matches the substring starting at index i
        printf("\nChecking substring starting at index %d: ", i);
        while (j < patternLen && text[i + j] == pattern[j]) {
            printf("Comparing text[%d] = '%c' with pattern[%d] = '%c' => Match\n", i + j, text[i + j], j, pattern[j]);
            j++;
        }

        // If pattern matches completely, print the index
        if (j == patternLen) {
            printf("Pattern found at index %d\n", i);
            break;
        } else {
            printf("Pattern does not match starting at index %d\n", i);
        }
    }

    return 0;
}
