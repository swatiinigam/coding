#include <vector>
#include <algorithm>
#include <climits>

class Solution {
private:
    // Recursive function to find the minimum cost with memoization
    int solve(int start, int end, std::vector<int>& cuts, std::vector<std::vector<int>>& memo) {
        if (start + 1 == end) {
            return 0; // No cost if there are no cuts between start and end
        }

        if (memo[start][end] != -1) {
            return memo[start][end]; // Return the memoized result if available
        }

        int minCost = INT_MAX;

        for (int i = start + 1; i < end; ++i) {
            // Calculate the cost of making the cut at cuts[i]
            int cost = cuts[end] - cuts[start] + solve(start, i, cuts, memo) + solve(i, end, cuts, memo);
            minCost = std::min(minCost, cost);
        }

        memo[start][end] = minCost; // Memoize the result
        return minCost;
    }

public:
    int minCost(int n, std::vector<int>& cuts) {
        int m = cuts.size();

        // Add the two ends of the rod
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort the cuts to make the problem easier to handle
        std::sort(cuts.begin(), cuts.end());

        // Create a memoization table initialized to -1
        std::vector<std::vector<int>> memo(cuts.size(), std::vector<int>(cuts.size(), -1));

        // Call the recursive function starting from the entire rod (0 to cuts.size()-1)
        return solve(0, cuts.size() - 1, cuts, memo);
    }
};