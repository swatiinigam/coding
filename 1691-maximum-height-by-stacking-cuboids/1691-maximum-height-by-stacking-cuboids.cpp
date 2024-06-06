#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
private:
    // Recursive function with memoization to find the maximum height for a cuboid at index i
    int maxHeightMemo(vector<vector<int>>& cuboids, int i, vector<int>& memo) {
        if (memo[i] != -1) {
            return memo[i];
        }
        
        int max_height = cuboids[i][2]; // Base height
        
        for (int j = 0; j < i; ++j) {
            if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                max_height = max(max_height, cuboids[i][2] + maxHeightMemo(cuboids, j, memo));
            }
        }
        
        return memo[i] = max_height;
    }

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        cuboids.push_back({0, 0, 0}); // Add a base case with dimensions (0, 0, 0)

        // Sort the cuboids based on their dimensions (non-decreasing order)
        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        vector<int> memo(n, -1); // Memoization array
        
        int max_height = 0;
        for (int i = 0; i < n; ++i) {
            max_height = max(max_height, maxHeightMemo(cuboids, i, memo));
        }

        return max_height;
    }
};
