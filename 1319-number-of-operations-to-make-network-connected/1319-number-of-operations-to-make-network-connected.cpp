#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    void dfs(int node, unordered_map<int, list<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // If there are not enough cables to connect all computers
        if (connections.size() < n - 1) {
            return -1;
        }

        // Create the adjacency list for the undirected graph
        unordered_map<int, list<int>> adj;
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Array to keep track of visited nodes
        vector<bool> vis(n, false);

        // Count the number of connected components
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                components++;
                dfs(i, adj, vis);
            }
        }

        // Number of operations needed to connect all components is components - 1
        return components - 1;
    }
};
