#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
private:
    int solve(vector<int>& obstacles, int n, int i, int currlane, vector<vector<int>>& dp) {
        if (i == n - 1) {
            return 0; // Reached the end
        }
        if (dp[i][currlane] != -1) {
            return dp[i][currlane];
        }
        
        int minJumps = INT_MAX;

        // Move forward if there's no obstacle in the current lane
        if (i < n - 1 && obstacles[i + 1] != currlane) {
            minJumps = min(minJumps, solve(obstacles, n, i + 1, currlane, dp));
        } else {
            // Try side jumps to other lanes
            for (int lane = 1; lane <= 3; ++lane) {
                if (lane != currlane && obstacles[i] != lane) {
                    minJumps = min(minJumps, 1 + solve(obstacles, n, i, lane, dp));
                }
            }
        }
        
        dp[i][currlane] = minJumps;
        return dp[i][currlane];
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(4, -1)); // dp[i][lane] to store min jumps needed to reach the end from position i and lane
        return solve(obstacles, n, 0, 2, dp); // Start from position 0, lane 2
    }
};
