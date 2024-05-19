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
    void inorder(TreeNode* temp,vector<int>&ans){
        if(!temp){
        return ;
        }
        inorder(temp->left,ans);
         ans.push_back(temp->val);
        inorder(temp->right,ans);
        //ans.push_back(temp->val);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
          vector<int>ans;
      inorder(root,ans);
        return ans;
    }
};