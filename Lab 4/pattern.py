def main():
    # Take user input for text and pattern
    text = input("Enter the text: ")
    pattern = input("Enter the pattern: ")

    textLen = len(text)
    patternLen = len(pattern)

    # Naive Pattern Matching Algorithm
    for i in range(textLen - patternLen + 1):
        j = 0

        # Check if pattern matches the substring starting at index i
        print(f"\nChecking substring starting at index {i}:")
        while j < patternLen and text[i + j] == pattern[j]:
            print(f"Comparing text[{i + j}] = '{text[i + j]}' with pattern[{j}] = '{pattern[j]}' => Match")
            j += 1

        # If pattern matches completely, print the index
        if j == patternLen:
            print(f"Pattern found at index {i}")
            break
        else:
            print(f"Pattern does not match starting at index {i}")

if __name__ == "__main__":
    main()
