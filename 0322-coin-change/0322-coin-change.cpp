#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a vector to store the minimum number of coins needed for each amount
        vector<int> dp(amount + 1, INT_MAX);
        
        // Base case: 0 coins needed for amount 0
        dp[0] = 0;
        
        // Iterate over each coin
        for (int coin : coins) {
            // Update dp array for each possible amount using the current coin
            for (int i = coin; i <= amount; ++i) {
                // Check if using the current coin reduces the number of coins needed
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If dp[amount] is still INT_MAX, it means it's not possible to make the amount
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
