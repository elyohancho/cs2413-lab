#include "student.h"
#include <stdlib.h>
#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    (void)nums1Size; // Unused parameter
    (void)nums2Size; // Unused parameter    

    int i = m - 1; // Pointer for the last element in the real part of nums1
    int j = n - 1; // Pointer for the last element in nums2
    int k = m + n - 1; // Pointer for the last position in nums1

    // Merge nums1 and nums2 from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If there are remaining elements in nums2, copy them
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
