#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], pattern[1000];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';  

    int textLen = strlen(text), patternLen = strlen(pattern);

    for (int i = 0; i <= textLen - patternLen; i++) {
        printf("\nChecking substring at index %d: ", i);
        int j;
        for (j = 0; j < patternLen; j++) {
            printf("Comparing '%c' with '%c' -> %s\n", text[i + j], pattern[j], (text[i + j] == pattern[j]) ? "Match" : "No Match");
            if (text[i + j] != pattern[j]) break;
        }
        if (j == patternLen) {
            printf("Pattern found at index %d\n", i);
            return 0;  // Exit after first match
        }
    }

    printf("Pattern not found.\n");
    return 0;
}
