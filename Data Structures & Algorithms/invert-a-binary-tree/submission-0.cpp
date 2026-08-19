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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
            return nullptr;

        deque<TreeNode*> dq;
        TreeNode* temp = root;
        dq.push_back(root);
        while(!dq.empty())
        {
            TreeNode* value = dq[0];
            temp = value->left;
            value->left=value->right;
            value->right = temp;

            dq.pop_front();
            if(value->right!=nullptr)
                dq.push_back(value->right);
            if(value->left!=nullptr)
                dq.push_back(value->left);
        }
        return root;
        
    }
};
