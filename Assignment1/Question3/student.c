#include <stdlib.h>
#include "student.h"
#include <stdio.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Start from the last digit and move backward
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i] += 1;
            *returnSize = digitsSize;
            return digits;
        }
        // Set current digit to 0 if it's 9
        digits[i] = 0;
    }

    // If all digits were 9, we need an extra digit at the beginning
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1; // Set the first digit to 1
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0; // Fill the rest with 0
    }
    *returnSize = digitsSize + 1;
    return result;
}

