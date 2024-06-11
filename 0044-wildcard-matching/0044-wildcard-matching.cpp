class Solution {
private:
    int solve(string& s, string& p, int n, int m, int i, int j, vector<vector<int>>& dp) {
        // If both strings are exhausted, return true
        if (i == n && j == m) {
            return 1;
        }
        // If only pattern is exhausted, return false
        if (j == m) {
            return 0;
        }
        // If only string is exhausted, check if all remaining characters in pattern are '*'
        if (i == n) {
            for (int k = j; k < m; ++k) {
                if (p[k] != '*') {
                    return 0;
                }
            }
            return 1;
        }
        // If result is already calculated, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int result = 0;
        // If characters match or pattern has '?', move both pointers
        if (s[i] == p[j] || p[j] == '?') {
            result = solve(s, p, n, m, i + 1, j + 1, dp);
        }
        // If pattern has '*', try both possibilities: advancing pattern pointer or advancing string pointer
        else if (p[j] == '*') {
            result = solve(s, p, n, m, i, j + 1, dp) || solve(s, p, n, m, i + 1, j, dp);
        }
        
        // Store result in memoization table
        return dp[i][j] = result;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(s, p, n, m, 0, 0, dp);
    }
};
