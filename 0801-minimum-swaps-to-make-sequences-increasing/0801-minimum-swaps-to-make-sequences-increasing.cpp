class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int swapped, vector<vector<int>>& dp) {
        int n = nums1.size();
        
        // Base case
        if (i == n) {
            return 0;
        }
        
        // Check memoization table
        if (dp[i][swapped] != -1) {
            return dp[i][swapped];
        }
        
        int ans = INT_MAX;
        
        // Previous values
        int prev1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int prev2 = (i == 0) ? INT_MIN : nums2[i - 1];
        
        if (swapped) {
            swap(prev1, prev2);
        }
        
        // Option 1: No swap
        if (nums1[i] > prev1 && nums2[i] > prev2) {
            ans = solve(nums1, nums2, i + 1, 0, dp);
        }
        
        // Option 2: Swap
        if (nums1[i] > prev2 && nums2[i] > prev1) {
            ans = min(ans, 1 + solve(nums1, nums2, i + 1, 1, dp));
        }
        
        // Memoize result
        return dp[i][swapped] = ans;
    }
    
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(nums1, nums2, 0, 0, dp);
    }
};