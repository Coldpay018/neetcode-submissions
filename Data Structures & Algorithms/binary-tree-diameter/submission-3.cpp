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
    int length(TreeNode* root)
    {
        if(root==nullptr)
            return 0;

        return 1 + max(length(root->left),length(root->right));
    }
    void dfs(TreeNode* root, int& ans)
    {
        if(root!=nullptr)
        {
            ans = max(ans, length(root->left) + length(root->right));
            dfs(root->left, ans);
            dfs(root->right, ans);
        }
        return;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int ans = 0;
        dfs(root, ans);
        return ans;
         
        
    }
};
