class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==1)
            return {{strs[0]}};
        vector<vector<string>> ans;
        vector<unordered_map<char,int>> hashmaps;
        bool continue_or_not = false;
        for(int i=0; i<strs.size(); i++)
        {
            continue_or_not = false;

            unordered_map<char,int> temp;
            for(char j: strs[i])
                temp[j]++;
            if(ans.empty())
            {
                ans.push_back({strs[i]});
                hashmaps.push_back(temp);
                continue;
            }

            for(int j = 0; j<hashmaps.size(); j++)
            {
                if(hashmaps[j]==temp)
                {
                    ans[j].push_back(strs[i]);
                    continue_or_not = true;
                }
            }
            if(continue_or_not == false)
            {
                ans.push_back({strs[i]});
                hashmaps.push_back(temp);
            }
        }
        return ans;

    }
};
