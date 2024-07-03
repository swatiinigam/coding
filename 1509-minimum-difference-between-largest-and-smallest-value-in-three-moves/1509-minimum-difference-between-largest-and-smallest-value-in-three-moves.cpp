class Solution {
public:
    int minDifference(vector<int>& nums) {
        // base case: we can make all the elements to the same value in the array
        int n = nums.size();
        if (n <= 4) return 0;

        // sort the integer array
        sort(nums.begin(), nums.end());

        // there are 4 possible choices
        return min({
            nums[n - 1] - nums[3],      // discard 0 biggest and 3 smallest
            nums[n - 2] - nums[2],      // discard 1 biggest and 2 smallest
            nums[n - 3] - nums[1],      // discard 2 biggest and 1 smallest
            nums[n - 4] - nums[0],      // discard 3 biggest and 0 smallest
        });
    }
};