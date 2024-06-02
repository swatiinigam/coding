#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // Initialize the DP array with the costs of the first two steps
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        // Iterate from the third step to the end
        for (int i = 2; i < n; ++i) {
            // Update dp[i] based on the recurrence relation
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        
        // Return the minimum of the costs of the last two steps
        return min(dp[n-1], dp[n-2]);
    }
};
