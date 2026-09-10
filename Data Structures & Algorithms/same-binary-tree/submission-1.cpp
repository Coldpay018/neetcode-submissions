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

    bool dfs(TreeNode* p, TreeNode* q)
    {
        if(p==nullptr || q==nullptr)
        {
            if(!(p==nullptr && q==nullptr))
                return false;
            return true;
        }
        else
        {
            if(p->val!=q->val)
                return false;
            bool a = dfs(p->left, q->left);
            bool b = dfs(p->right, q->right);
            if(a==false || b==false)
            {
                return false;
            }
        }
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);

    }
};
