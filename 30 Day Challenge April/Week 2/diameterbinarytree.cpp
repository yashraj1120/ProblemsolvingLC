/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    int max_d=INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        helper(root);
        return max_d;
    }
    
    int helper(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
       int l =helper(root->left);
        int r = helper(root->right);
        max_d = max(max_d,l+r);
        return max(l,r)+1;
    }
};