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
    void dfs(TreeNode* root, int& count, int m)
    {
        if(root == nullptr)
            return;
        
        if(m<=root->val)
        {
            count++;
            m = root->val;
        }
        dfs(root->left, count, m);
        dfs(root->right,count, m);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        int m = INT_MIN;
        dfs(root,count,m);
        return count;

    }
};
