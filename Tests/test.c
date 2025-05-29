#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare the function from solution.c
char** letterCasePermutation(char* s, int* returnSize);

int compareStr(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    char* testInputs[] = {
        "a1b", "3z4", "12345", "0", "A", "ab", "a1B2", "C", "c7D8e", "Zz"
    };

    char* expectedOutputs[][16] = {
        {"a1b", "a1B", "A1b", "A1B"},
        {"3z4", "3Z4"},
        {"12345"},
        {"0"},
        {"a", "A"},
        {"ab", "aB", "Ab", "AB"},
        {"a1b2", "a1B2", "A1b2", "A1B2"},
        {"c", "C"},
        {"c7d8e", "c7d8E", "c7D8e", "c7D8E", "C7d8e", "C7d8E", "C7D8e", "C7D8E"},
        {"zz", "zZ", "Zz", "ZZ"}
    };

    int expectedSizes[] = {4, 2, 1, 1, 2, 4, 4, 2, 8, 4};

    int allPassed = 1;

    for (int i = 0; i < 10; i++) {
        int returnSize = 0;
        // Copy input because letterCasePermutation modifies it in-place
        char inputCopy[100];
        strcpy(inputCopy, testInputs[i]);

        char** actual = letterCasePermutation(inputCopy, &returnSize);

        // Sort actual results
        qsort(actual, returnSize, sizeof(char*), compareStr);

        // Sort expected results
        qsort(expectedOutputs[i], expectedSizes[i], sizeof(char*), compareStr);

        printf("Test Case %d: \"%s\"\n", i + 1, testInputs[i]);
        printf("Expected: ");
        for (int j = 0; j < expectedSizes[i]; j++) {
            printf("%s ", expectedOutputs[i][j]);
        }
        printf("\nActual:   ");
        for (int j = 0; j < returnSize; j++) {
            printf("%s ", actual[j]);
        }
        printf("\n");

        if (returnSize != expectedSizes[i]) {
            printf("❌ Test Case %d Failed (size mismatch)\n", i + 1);
            allPassed = 0;
        } else {
            // Check each string
            for (int j = 0; j < returnSize; j++) {
                if (strcmp(actual[j], expectedOutputs[i][j]) != 0) {
                    printf("❌ Test Case %d Failed (mismatch at index %d)\n", i + 1, j);
                    allPassed = 0;
                    break;
                }
            }
            if (allPassed)
                printf("✅ Test Case %d Passed\n", i + 1);
        }
        printf("--------------------------\n");

        // Free memory allocated by letterCasePermutation
        for (int j = 0; j < returnSize; j++) {
            free(actual[j]);
        }
        free(actual);
    }

    if (allPassed) {
        printf("🎉 All test cases passed!\n");
        return 0;
    } else {
        printf("❌ Some test cases failed.\n");
        return 1;
    }
}
