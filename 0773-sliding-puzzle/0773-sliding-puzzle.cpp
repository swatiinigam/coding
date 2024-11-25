class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Directions for possible swaps based on '0' position
        vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450";
        set<string> vis; // Track visited configurations
        queue<string> q;
        string start = "";

        // Convert 2D board to a single string
        for (auto row : board) {
            for (auto col : row) {
                start += col + '0';
            }
        }

        q.push(start);
        vis.insert(start);
        int step = 0;

        // Perform BFS
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string current = q.front();
                q.pop();

                // Check if target is reached
                if (current == target) return step;

                int zero = current.find('0'); // Find position of '0'

                // Generate next moves
                for (auto move : dir[zero]) {
                    string next = current;
                    swap(next[move], next[zero]);
                    if (!vis.count(next)) { // Add unvisited states to the queue
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            step++;
        }
        return -1; // Return -1 if target is unreachable
    }
};