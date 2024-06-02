#include <vector>
#include <algorithm> // for min
using namespace std;

class Solution {
private:
    int solve(vector<int>& cost, int n, int i,vector<int>&dp) {
        // Base case: if the current index reaches or exceeds the top of the stairs
        if (i >= n) {
            return 0;
        }
        if(dp[i]!=-1){
          return dp[i];
        }
        
        // Calculate the minimum cost for reaching the top from the current index
        int minCost = cost[i] + min(solve(cost, n, i + 1,dp), solve(cost, n, i + 2,dp));
         
        dp[i]= minCost;
        return dp[i];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //memo
        vector<int>dp(n+1,-1);
        
        // Calculate the minimum cost starting from the bottom step
        int minCostFromBottom = min(solve(cost, n, 0,dp), solve(cost, n, 1,dp));
        
        // Return the minimum cost from either starting from the 0th or 1st index
        return minCostFromBottom;
    }
};