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
    bool dfs(TreeNode* root, long long mi, long long ma)
    {
        if(root!=nullptr)
        {
            if(root->val > mi && root->val < ma)
            {
                if(root->left!=nullptr && root->right!=nullptr)
                {
                    bool a = dfs(root->left,mi,root->val);
                    bool b = dfs(root->right,root->val,ma);
                    return a && b;
                }
                else if(root->left!=nullptr)
                    return dfs(root->left, mi, root->val);
                else if(root->right!=nullptr)
                    return dfs(root->right, root->val, ma);
                else
                    return true;
            }
            else
                return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long min_range = LLONG_MIN;
        long long max_range = LLONG_MAX;
        return dfs(root, min_range, max_range);
    }
};
