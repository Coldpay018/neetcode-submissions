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
    int max_height(TreeNode* root)
    {
        if(root == nullptr)    
            return 0;

        return 1 + max(max_height(root->left), max_height(root->right));
    }
    void finding_diameter_of_every_node(TreeNode*& root, int& a)
    {
        TreeNode* temp = root;
        while(true)
        {
            if(temp==nullptr)
                return;

            int l = max_height(temp->left);
            int r = max_height(temp->right);

            a = max(a,l+r);

            finding_diameter_of_every_node(temp->left,a);
            finding_diameter_of_every_node(temp->right,a);
            break;

        }

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int a=0;
        finding_diameter_of_every_node(root,a);
        return a;

        
    }
};
