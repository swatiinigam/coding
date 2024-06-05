class Solution {
    
    private:
    int solve(int num,vector<int>&dp)
    {
        int mini =INT_MAX;
      if(num==0){
          return 0;
      }
        if(dp[num]!=-1){
            return dp[num];
        }
        for(int i=1;i*i<=num;i++){
     int minicnt= 1+  solve(num-i*i,dp);
          mini=min(minicnt,mini);
    }
        dp[num]=mini;
        return dp[num];
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};

