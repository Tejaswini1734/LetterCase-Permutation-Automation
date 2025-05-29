#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void helper(char* s, int index, char*** res, int* returnSize, int* capacity);

char** letterCasePermutation(char* s, int* returnSize) {
    int capacity = 100;  // Initial capacity for results
    char** res = (char**)malloc(capacity * sizeof(char*));
    *returnSize = 0;
    helper(s, 0, &res, returnSize, &capacity);
    return res;
}

void helper(char* s, int index, char*** res, int* returnSize, int* capacity) {
    int len = strlen(s);
    if (index == len) {
        // Add a copy of current string to results
        char* copy = (char*)malloc((len + 1) * sizeof(char));
        strcpy(copy, s);

        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *res = (char**)realloc(*res, (*capacity) * sizeof(char*));
        }
        (*res)[*returnSize] = copy;
        (*returnSize)++;
        return;
    }

    if (isalpha(s[index])) {
        s[index] = tolower(s[index]);
        helper(s, index + 1, res, returnSize, capacity);

        s[index] = toupper(s[index]);
        helper(s, index + 1, res, returnSize, capacity);
    } else {
        helper(s, index + 1, res, returnSize, capacity);
    }
}
