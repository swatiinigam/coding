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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if root is null or the root's value is the one we're looking for
        if (!root || root->val == val) {
            return root;
        }

        // Recursively search in the left subtree if the value is less than the root's value
        if (val < root->val) {
            return searchBST(root->left, val);
        } 
        // Otherwise, recursively search in the right subtree
        else {
            return searchBST(root->right, val);
        }
    }
};
