class Solution {
private:
    void solve(vector<int>& nums, int i, int n, vector<int>& subset, vector<vector<int>>& subsets) {
        if (i == n) {
            subsets.push_back(subset);
            return;
        }
        
        // Exclude current element
        solve(nums, i + 1, n, subset, subsets);
        
        // Include current element
        subset.push_back(nums[i]);
        solve(nums, i + 1, n, subset, subsets);
        subset.pop_back();
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        solve(nums, 0, nums.size(), subset, subsets);
        return subsets;
    }
};
