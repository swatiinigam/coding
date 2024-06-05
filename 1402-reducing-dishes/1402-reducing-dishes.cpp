#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int solve(vector<int>& satisfaction, int i, int dish, vector<vector<int>>& dp) {
        if (i >= satisfaction.size()) {
            return 0;
        }
        if (dp[i][dish] != -1) {
            return dp[i][dish];
        }
        
        int include = satisfaction[i] * dish + solve(satisfaction, i + 1, dish + 1, dp);
        int exclude = solve(satisfaction, i + 1, dish, dp);
        
        dp[i][dish] = max(include, exclude);
        return dp[i][dish];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(satisfaction, 0, 1, dp);
    }
};
