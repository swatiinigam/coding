#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // If there are not enough connections, return -1
        if (connections.size() < n - 1) {
            return -1;
        }

        // Create the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        // Count the number of connected components using DFS
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++components;
                dfs(i, adj, visited);
            }
        }

        // Minimum operations needed is the number of components - 1
        return components - 1;
    }
};
