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
    void bfs(TreeNode* root, vector<vector<int>>& ans, int& i, queue<TreeNode*>& q)
    {
        while(q.empty()==false)
        {
            ans.push_back({});
            int count = 0;
            int l = q.size();
            while(count!=l)
            {
                ans[i].push_back(q.front()->val);

                if(q.front()->left!=nullptr)
                    q.push(q.front()->left);
                if(q.front()->right!=nullptr)
                    q.push(q.front()->right);
                q.pop();

                count++;
            }
            i++;
        }
        return;
        
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        int i = 0;
        queue<TreeNode*> q;
        q.push(root);

        bfs(root, ans, i, q);
        return ans;

    }
};
