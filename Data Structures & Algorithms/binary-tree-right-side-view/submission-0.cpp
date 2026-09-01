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
    void bfs(queue<TreeNode*>& q, int& i, vector<vector<int>>& ans)
    {
        while(!q.empty())
        {
            ans.push_back({});
            int count= q.size();
            int j = 0;
            while(j!=count)
            {
                if(q.front()->right!=nullptr)
                    q.push(q.front()->right);
                if(q.front()->left!=nullptr)
                    q.push(q.front()->left);
                ans[i].push_back(q.front()->val);
                q.pop();
                j++;
            }
            i++;
        }
        return;
    }
    vector<int> rightSideView(TreeNode* root) {

        if(root==nullptr)
            return {};

        int i = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        bfs(q,i,ans);

        vector<int> right_side;
        for(int i=0; i<ans.size(); i++)
        {
            right_side.push_back(ans[i][0]);
        }
        return right_side;
    }
};
