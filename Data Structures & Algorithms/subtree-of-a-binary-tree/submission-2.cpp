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
    bool cmp(TreeNode* root, TreeNode* subRoot)
    {
        if(root==nullptr || subRoot == nullptr)
        {
            if(!(root==nullptr && subRoot==nullptr))
                return false;
            else
                return true;
        }
        if(root->val == subRoot->val)
        {
            bool left = cmp(root->left, subRoot->left);
            bool right = cmp(root->right, subRoot->right);
            if(left== true && right==true)
                return true;
        }
        return false;
    }
    void bfs(TreeNode* root, TreeNode* subRoot, int& flag)
    {
        if(root!=nullptr)
        {
            bool a = cmp(root, subRoot);
            bool b = cmp(root->left, subRoot);
            bool c = cmp(root->right, subRoot);
            if(a==true || b==true || c==true)
            {
                flag=1;
                return;
            }
            bfs(root->left, subRoot, flag);
            bfs(root->right, subRoot, flag);
        }
        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        int flag = 0;
        bfs(root, subRoot, flag);
        if(flag==1)
            return true;
        return false;
        
    }
};
