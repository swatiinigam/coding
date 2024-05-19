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
    private:
    void postorder(TreeNode* temp,vector<int>&ans){
        if(!temp){
        return ;
        }
        postorder(temp->left,ans);
        postorder(temp->right,ans);
        ans.push_back(temp->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
      postorder(root,ans);
        return ans;
    }
};