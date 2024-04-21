//
//  main.c
//  Rabin-Karp
//
//  Created by Md Moinuddin Quazi on 4/21/24.
//

#include <stdio.h>
#include <string.h>
#define PRIME 101
// Function to calculate hash value for a given string
int calculate_hash(char* str, int length) {
    int hash = 0;
    for (int i = 0; i < length; i++) {
        hash = (hash * PRIME + str[i]) % PRIME;
    }
    return hash;
}
// Function to implement Rabin-Karp algorithm
int rabin_karp(char* text, char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int pattern_hash = calculate_hash(pattern, m);
    int text_hash = calculate_hash(text, m);
    for (int i = 0; i <= n - m; i++) {
        if (text_hash == pattern_hash) {
            // Check if pattern matches substring of text
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                return i; // Pattern found at index i
        }
        if (i < n - m) {
            // Recalculate hash for the next substring of text
            text_hash = (text_hash - text[i] * PRIME) % PRIME;
            if (text_hash < 0)
                text_hash += PRIME;
            text_hash = (text_hash * PRIME + text[i + m]) % PRIME;
        }
    }
    return -1; // Pattern not found
}

int main() {
    char text[] = "Analysisofalgorithms";
    char pattern[] = "algorithms";

    int index = rabin_karp(text, pattern);

    if (index != -1) {
        printf("Pattern found at index: %d\n", index);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}
