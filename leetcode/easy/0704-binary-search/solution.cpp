class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // Prevents integer overflow
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1; // Target lies in the right half
            } else {
                right = mid - 1; // Target lies in the left half
            }
        }
        return -1; // Target not found
    }
};
