class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i=0; i<strs.size(); i++)
        {
            s+=strs[i]+'~';
        }
        return s;
    }

    vector<string> decode(string s) {

        vector<string> ans;
        int i=0;
        while(i<s.size())
        {
            string a = "";
            while(s[i]!='~')
            {
                a+=s[i];
                i++;
            }
            i++;
            ans.push_back(a);
        }
        return ans;
    }
};
