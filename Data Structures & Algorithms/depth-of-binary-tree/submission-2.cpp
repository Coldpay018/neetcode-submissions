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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int depth = 0;
        int current_level = dq.size();
        while(!dq.empty())
        {
            if(current_level==0)
                current_level = dq.size();

            TreeNode* bottom = dq.front();
            if(bottom->left!=nullptr)
                dq.push_back(bottom->left);
            if(bottom->right!=nullptr)
                dq.push_back(bottom->right);
            dq.pop_front();
            
            current_level--;
            if(current_level==0)
                depth++;
        }
        return depth;
    }
};
