class Solution {
private:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp, vector<vector<int>>& maxVal) {
        if (i == j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int left = solve(arr, i, k, dp, maxVal);
            int right = solve(arr, k + 1, j, dp, maxVal);
            int cost = left + right + maxVal[i][k] * maxVal[k + 1][j];
            ans = min(ans, cost);
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> maxVal(n, vector<int>(n, 0));
        
        // Initialize maxVal array to store the maximum leaf value in each subarray arr[i:j]
        for (int i = 0; i < n; i++) {
            maxVal[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxVal[i][j] = max(maxVal[i][j - 1], arr[j]);
            }
        }

        return solve(arr, 0, n - 1, dp, maxVal);
    }
};
