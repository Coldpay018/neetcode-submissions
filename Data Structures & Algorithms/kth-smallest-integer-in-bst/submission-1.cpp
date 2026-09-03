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
    bool inorder(TreeNode* root, int& count, int k, int& ans)
    {
        if(root==nullptr)
            return false;
        if(inorder(root->left, count, k, ans))
            return true;

        count++;
        if(count==k)
        {
            ans = root->val;
            return true;
        }

        return inorder(root->right, count, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        inorder(root, count, k, ans);
        return ans;
    }
};
