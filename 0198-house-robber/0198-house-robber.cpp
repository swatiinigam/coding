class Solution {
    
private:
int solve(vector<int>&nums,int i,int n,vector<int>&dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int maxamnt=max( nums[i]+solve(nums,i+2,n,dp),solve(nums,i+1,n,dp));
    dp[i]=maxamnt;
    return dp[i];
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,0,n,dp);
    }
};