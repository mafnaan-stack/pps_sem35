# Running Sum of 1d Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an array `nums`. We define a running sum of an array as `runningSum[i] = sum(nums[0]…nums[i])`.

Return the running sum of `nums`.

 

Original
C
 **Example 1:** 

```
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
```

 **Example 2:** 

```
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
```

 **Example 3:** 

```
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]

```

 

 **Constraints:** 

- 1 <= nums.length <= 1000
- -10^6 <= nums[i] <= 10^6

## Solution

**Language:** C  
**Runtime:** 1 ms (beats 5.70%)  
**Memory:** 11.8 MB (beats 39.44%)  
**Submitted:** 2026-11-25T08:51:17.977Z  

```c
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
```

---

[View on LeetCode](https://leetcode.com/problems/running-sum-of-1d-array/)