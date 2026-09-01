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
    void bfs(queue<TreeNode*>& q, vector<int>& ans)
    {
        while(!q.empty())
        {
            int count= q.size();
            int j = 0;
            bool flag = false;
            while(j!=count)
            {
                if(q.front()->right!=nullptr)
                    q.push(q.front()->right);
                if(q.front()->left!=nullptr)
                    q.push(q.front()->left);
                if(flag == false)
                {
                    ans.push_back(q.front()->val);
                    flag = true;
                }
                q.pop();
                j++;
            }
        }
        return;
    }
    vector<int> rightSideView(TreeNode* root) {

        if(root==nullptr)
            return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        bfs(q,ans);
        return ans;
    }
};
