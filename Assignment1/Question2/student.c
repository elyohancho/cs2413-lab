#include "student.h"
#include <stdlib.h>
#include <stdio.h>

// Given an array nums of size n, return the majority element.
// The majority element appears more than ⌊n/2⌋ times.
// You may assume the majority element always exists in the array.

int majorityElement(int* nums, int numsSize) {
     int count = 0;
     int candidate = 0;

     // Phase 1: Find a candidate for the majority element
     for (int i = 0; i < numsSize; i++) {
          if (count == 0) {
               candidate = nums[i];
               count = 1;
          } else if (nums[i] == candidate) {
               count++;
          } else {
               count--;
          }
     }

     // Phase 2: Verify the candidate (optional, since the problem guarantees a majority element)
     count = 0;
     for (int i = 0; i < numsSize; i++) {
          if (nums[i] == candidate) {
               count++;
          }
     }

     if (count > numsSize / 2) {
          return candidate;
     }

     // This line should never be reached as per the problem's assumption
     return -1;
}
