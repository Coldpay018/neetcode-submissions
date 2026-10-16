class Solution {
public:
    queue<string> q;
    string encode(vector<string>& strs) {
        string s="";
        for(int i=0; i<strs.size(); i++)
        {
            q.push(strs[i]);
            s+=strs[i];
        }
        return s;

    }

    vector<string> decode(string s) {
        vector<string> ans;
        while(!q.empty())
        {
            string a = q.front();
            q.pop();
            ans.push_back(a);
        }
        return ans;

    }
};
