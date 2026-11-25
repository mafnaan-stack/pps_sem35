#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    // 1. Allocate heap memory for the output array
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    // 2. Initialize base case
    result[0] = nums[0];
    
    // 3. Compute cumulative sums iteratively
    for (int i = 1; i < numsSize; ++i) {
        result[i] = result[i - 1] + nums[i];
    }
    
    // 4. Assign size and return
    *returnSize = numsSize;
    return result;
}