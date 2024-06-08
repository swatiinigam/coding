class Solution {
    
private:
    int solve(int n,vector<int>&dp){
     if(n== 1 || n==0){
      return 1;
     }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
      for(int i=1;i<=n;i++){
          ans+=solve(i-1,dp)*solve(n-i,dp);
      }  
        dp[n]=ans;
        return dp[n];
    }
public:
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};