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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        if (root == nullptr)
            return new TreeNode(val);
        while(true)
        {
            if(root->val>val)
            {
                if(root->left==nullptr)
                {
                    root->left = new TreeNode(val);
                    return temp;
                }
                root = root->left;
                
            }

            else
            {
                if(root->right==nullptr)
                {
                    root->right = new TreeNode(val);
                    return temp;
                }
                root = root->right;
            }
        }

    }
};