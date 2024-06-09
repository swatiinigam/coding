class Solution {
private:
    int solve(vector<int>& prices, int i, int n, int minPrice) {
        if (i == n)
            return 0;
        
        // Calculate the profit if we sell on the current day
        int sellToday = max(0, prices[i] - minPrice);
        
        // Recur for the next day
        int nextProfit = solve(prices, i + 1, n, min(minPrice, prices[i]));
        
        // Return the maximum of profit by selling today or not selling today
        return max(sellToday, nextProfit);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        
        return solve(prices, 0, n, prices[0]);
    }
};
