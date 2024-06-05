#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
private:
    int solve(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
        if (j - i < 2) {
            return 0;  // No triangle can be formed
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int minScore = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            int score = values[i] * values[j] * values[k] +
                        solve(values, i, k, dp) +
                        solve(values, k, j, dp);
            minScore = min(minScore, score);
        }
        
        dp[i][j] = minScore;
        return dp[i][j];
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(values, 0, n - 1, dp);
    }
};
