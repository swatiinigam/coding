#include <vector>
#include <algorithm>

class Solution {
public:
    int minIncrementForUnique(std::vector<int>& nums) {
        // Sort the array to handle duplicates in a sequential manner
        std::sort(nums.begin(), nums.end());
        
        int cnt = 0;  // To count the number of increments
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                int needed_increment = nums[i - 1] - nums[i] + 1;
                nums[i] += needed_increment;
                cnt += needed_increment;
            }
        }
        
        return cnt;
    }
};
