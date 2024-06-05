class Solution {
    int solve(vector<int>& days, vector<int>& costs, int i, int n, vector<int>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        
        // 1-day pass
        int oneDayPass = costs[0] + solve(days, costs, i + 1, n, dp);

        // 7-day pass
        int j = i;
        while (j < n && days[j] < days[i] + 7) {
            j++;
        }
        int sevenDayPass = costs[1] + solve(days, costs, j, n, dp);

        // 30-day pass
        j = i;
        while (j < n && days[j] < days[i] + 30) {
            j++;
        }
        int thirtyDayPass = costs[2] + solve(days, costs, j, n, dp);

        dp[i] = min({oneDayPass, sevenDayPass, thirtyDayPass});
        return dp[i];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);  // Memoization table
        return solve(days, costs, 0, n, dp);
    }
};
