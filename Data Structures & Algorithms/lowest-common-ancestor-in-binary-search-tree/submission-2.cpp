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

    bool contains_the_node(TreeNode* root, TreeNode* p)
    {
        if(root==nullptr)
            return false;
        if(root->val == p->val)
            return true;
        bool a = contains_the_node(root->left,p);
        bool b = contains_the_node(root->right,p);
        if(a==false && b==false)
            return false;
        return true;
    }
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& node)
    {
        if(root!=nullptr)
        {
            if(root->val < min(p->val, q->val))
                dfs(root->right,p,q,node);
            else if(root->val > max(p->val, q->val))
                dfs(root->left, p, q, node);
            
            else if(contains_the_node(root,p) && contains_the_node(root,q))
            {
                node = root;
                dfs(root->left,p,q,node);
                dfs(root->right,p,q,node);
            }
                return;
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        dfs(root,p,q,node);
        return node;

        
    }
};
