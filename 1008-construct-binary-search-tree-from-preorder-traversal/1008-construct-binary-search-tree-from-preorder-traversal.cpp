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
#include <vector>
using namespace std;

// Definition for a binary tree node.


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBST(preorder, index, INT_MIN, INT_MAX);
    }

private:
    TreeNode* buildBST(const vector<int>& preorder, int& index, int minVal, int maxVal) {
        // Base case: if all elements are processed or the current element is out of bounds
        if (index >= preorder.size() || preorder[index] < minVal || preorder[index] > maxVal) {
            return nullptr;
        }

        // The current element is the root of this subtree
        int val = preorder[index++];
        TreeNode* root = new TreeNode(val);

        // All elements in the left subtree should be less than the root's value
        root->left = buildBST(preorder, index, minVal, val);

        // All elements in the right subtree should be greater than the root's value
        root->right = buildBST(preorder, index, val, maxVal);

        return root;
    }
};

// Helper function to print in-order traversal (for testing)
