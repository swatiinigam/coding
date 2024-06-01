#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& island) {
        // Base conditions
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
            return;
        }
        
        // Mark the cell as part of the island
        grid[i][j] = 2;
        island.push_back({i, j});
        
        // Explore all 4 directions
        dfs(grid, i + 1, j, island);
        dfs(grid, i - 1, j, island);
        dfs(grid, i, j + 1, island);
        dfs(grid, i, j - 1, island);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int, int>> island1, island2;
        bool found = false;

        // Find the first island and mark it
        for (int i = 0; i < grid.size(); ++i) {
            if (found) break;
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, island1);
                    found = true;
                    break;
                }
            }
        }

        // Use BFS to find the shortest bridge from island1 to any cell of island2
        queue<pair<int, int>> q;
        for (auto cell : island1) {
            q.push(cell);
        }

        int steps = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dirs[k];
                    int ny = y + dirs[k + 1];

                    if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
                        if (grid[nx][ny] == 1) {
                            return steps;
                        }
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            ++steps;
        }

        return -1; // This line should not be reached
    }
};