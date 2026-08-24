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
    int max_height(TreeNode* root, int& d)
    {
        if(root==nullptr)
            return 0;
        int left = max_height(root->left,d);
        int right = max_height(root->right,d);
        d = max(d,left+right);
        return 1 + max(left,right);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        max_height(root,d);
        return d;
        
    }
};
