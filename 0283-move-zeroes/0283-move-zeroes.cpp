class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int j = i + 1;
        while (j < n) {
            if (nums[i] == 0 && nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
            else if (nums[i] != 0) {
                i++;
            }
            j++;
        }
    }
};
