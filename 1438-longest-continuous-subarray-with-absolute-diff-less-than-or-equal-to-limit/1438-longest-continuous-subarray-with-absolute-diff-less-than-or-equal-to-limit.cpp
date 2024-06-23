class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxLength = 0;
        
        multiset<int> window;
        
        while (j < n) {
            window.insert(nums[j]);
            
            int mini = *window.begin();
            int maxi = *window.rbegin();
            
            if (maxi - mini <= limit) {
                maxLength = max(maxLength, j - i + 1);
                j++;
            } else {
                window.erase(window.find(nums[i]));
                i++;
                j++;
            }
        }
        
        return maxLength;
    }
};
