class Solution {
    private:
    int func(int ind,int buy,vector<int>&prices,vector<vector<vector<int>>> &dp,int n,int l){
    if(l==0){
        return 0;
    }
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy][l]!=-1) return dp[ind][buy][l];
        if(buy){
            return dp[ind][buy][l]= max(-prices[ind]+func(ind+1,0,prices,dp,n,l),
             func(ind+1,1,prices,dp,n,l));
        }
        else{
            return dp[ind][buy][l] = max(prices[ind]+func(ind+1,1,prices,dp,n,l-1),func(ind+1,0,prices,dp,n,l));
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
   // int l=2;
     return func(0,1,prices,dp,n,k);
    }
};