#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp; // DP array to store lengths of longest subsequences

        int maxCount = 0;
        for (int num : arr) {
            // Update the length of the current subsequence
            // Length at current index = Length at index (num - difference) + 1
            dp[num] = dp[num - difference] + 1;
            
            // Update the maximum length found so far
            maxCount = max(maxCount, dp[num]);
        }

        return maxCount;
    }
};
