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
    void bfs(TreeNode* p, TreeNode* q, int& flag)
    {
        if(p==nullptr && q==nullptr)
            return;

        if(p==nullptr && q!=nullptr)
        {
            flag=1; 
            return;
        }
        if(p!=nullptr && q==nullptr)
        {
            flag=1;
            return;
        }
        
        if(p->val != q->val)
        {
            flag = 1;
            return;
        }

        bfs(p->left,q->left,flag);
        bfs(p->right,q->right,flag);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int flag = 0;
        bfs(p,q,flag);
        if(flag==0)
            return true;
        return false;
    }
};
