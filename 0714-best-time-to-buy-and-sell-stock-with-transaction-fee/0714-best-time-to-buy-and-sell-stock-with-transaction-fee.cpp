class Solution {
    private:
    int func(int ind,int buy,vector<int>&prices,vector<vector<int>> &dp,int n,int fee){
    
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy]= max(-prices[ind]+func(ind+1,0,prices,dp,n,fee),
             func(ind+1,1,prices,dp,n,fee));
        }
        else{
            return dp[ind][buy] = max(prices[ind]-fee+func(ind+1,1,prices,dp,n,fee),func(ind+1,0,prices,dp,n,fee));
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    //int l=2;
     return func(0,1,prices,dp,n,fee);
    }
};