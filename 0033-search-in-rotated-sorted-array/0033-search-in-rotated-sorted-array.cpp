#include <vector>
#include <algorithm>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size();
        
        // Finding the rotation index
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int rotationIndex = left;
        left = 0;
        right = n - 1;
        
        // Regular binary search with rotation considered
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int realMid = (mid + rotationIndex) % n;
            if (nums[realMid] == target) {
                return realMid;
            } else if (nums[realMid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};
