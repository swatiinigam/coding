class Solution {
    private:
    int h(vector<int>&nums, int target, int i, int sum){
        if(i >= nums.size())
        return target == sum;
        int a = h(nums, target, i + 1, sum + nums[i]);
        int s = h(nums, target, i + 1, sum - nums[i]);
        return a + s;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return h(nums, target, 0, 0);
    }
};