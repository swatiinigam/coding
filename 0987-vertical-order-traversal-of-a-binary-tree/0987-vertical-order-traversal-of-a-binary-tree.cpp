/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        // Map to store the vertical order traversal
        // Key: horizontal distance, Value: multiset of pairs (level, node value)
        map<int, multiset<pair<int, int>>> verticalMap;
        queue<pair<TreeNode*, pair<int, int>>> q; // Node, (horizontal distance, level)

        q.push({root, {0, 0}}); // Start with the root at horizontal distance 0, level 0

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            TreeNode* current = front.first;
            int hd = front.second.first;
            int level = front.second.second;

            // Insert the current node's value into the multiset at its horizontal distance
            verticalMap[hd].insert({level, current->val});

            if (current->left) {
                q.push({current->left, {hd - 1, level + 1}});
            }
            if (current->right) {
                q.push({current->right, {hd + 1, level + 1}});
            }
        }

        // Extract the values from the map in vertical order
        for (auto &entry : verticalMap) {
            vector<int> verticalLevel;
            for (auto &node : entry.second) {
                verticalLevel.push_back(node.second);
            }
            result.push_back(verticalLevel);
        }

        return result;
    }
};
