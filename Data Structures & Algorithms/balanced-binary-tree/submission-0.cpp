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
    int max_height(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int l = max_height(root->left);
        int r = max_height(root->right);
        return 1 + max(l,r);
    }

    int comparing_subtrees(TreeNode* root, int& flag)
    {
        if(root==nullptr)
            return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int diff = abs(max_height(left)-max_height(right));
        if(diff>1)
        {
            flag = 1;
            return 0;
        }
        comparing_subtrees(left,flag);
        comparing_subtrees(right,flag);
        return 1;
    }
    bool isBalanced(TreeNode* root) {
        int flag = 0;
        int cs = comparing_subtrees(root,flag);
        if(flag==1)
            return false;
        return true;
    }
};
